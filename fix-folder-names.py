#!/usr/bin/env python2.7
import os
import re


def canonicalize_folder_name(raw_name):
    parts = re.sub('[^a-z0-9]', ' ', raw_name.lower()).split(' ')
    slug = '-'.join(filter(None, parts))
    return slug


def fix_folder_names(starting_dir):
    for root, dirs, files in os.walk(starting_dir, topdown=False):
        for dir in dirs:
            if dir.startswith("."):
                continue

            dirpath = os.path.join(root, dir)
            new_folder_name = canonicalize_folder_name(dir)
            new_dirpath = os.path.join(root, new_folder_name)

            if dir != new_folder_name:
                print dirpath, "->", new_folder_name
                os.rename(dirpath, new_dirpath)


def main():
    starting_dir = os.path.join(os.path.dirname(__file__), './')
    fix_folder_names(starting_dir)


if __name__ == "__main__":
    main()
