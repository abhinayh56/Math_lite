import os

ORDERED_FOLDERS = [
    "include",
    "src",
    "tests",
    "examples",
    "docs",
    "tools",
    "dist"
]

# Paths to exclude, relative to root_path
EXCLUDED_PATHS = [
    "tools",
    # "src/temp",
    # "include/math_lite/internal.h",
]


def write_filtered_tree(root_path, output_file):
    root_path = os.path.abspath(root_path)

    # Normalize excluded paths to absolute paths
    excluded_paths = {
        os.path.normpath(os.path.abspath(os.path.join(root_path, path)))
        for path in EXCLUDED_PATHS
    }

    lines = []

    def is_excluded(path):
        return os.path.normpath(path) in excluded_paths

    def build_tree(path, prefix=""):
        try:
            entries = sorted(os.listdir(path))
        except PermissionError:
            return

        # Remove excluded entries
        entries = [
            entry
            for entry in entries
            if not is_excluded(os.path.join(path, entry))
        ]

        entries_count = len(entries)

        for i, entry in enumerate(entries):
            full_path = os.path.join(path, entry)
            is_last = (i == entries_count - 1)

            connector = "└── " if is_last else "├── "
            line = prefix + connector + entry

            if os.path.isdir(full_path):
                lines.append(line + "/")
                new_prefix = prefix + ("    " if is_last else "│   ")
                build_tree(full_path, new_prefix)
            else:
                lines.append(line)

    # Root
    lines.append(os.path.basename(root_path) + "/")

    # Only include selected subfolders in fixed order
    existing = [
        f for f in ORDERED_FOLDERS
        if os.path.isdir(os.path.join(root_path, f))
        and not is_excluded(os.path.join(root_path, f))
    ]

    total = len(existing)

    for i, folder in enumerate(existing):
        full_path = os.path.join(root_path, folder)
        is_last = (i == total - 1)

        connector = "└── " if is_last else "├── "
        lines.append(connector + folder + "/")

        prefix = "    " if is_last else "│   "
        build_tree(full_path, prefix)

    with open(output_file, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))


if __name__ == "__main__":
    folder_path = "../Math_lite"
    output_file = "../Math_lite/tools/folder_tree.txt"
    write_filtered_tree(folder_path, output_file)
    print(f"Saved hierarchy to {output_file}")