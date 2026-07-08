from pathlib import Path

# Count all Arduino (.ino) files in the repository
ino_files = list(Path(".").rglob("*.ino"))

print("=" * 40)
print("Arduino (.ino) File Counter")
print("=" * 40)
print(f"Total .ino files found: {len(ino_files)}")
print("=" * 40)

print("\nList of .ino files:")
for file in ino_files:
    print(file)
