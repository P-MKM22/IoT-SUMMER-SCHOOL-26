from pathlib import Path

count = len(list(Path(".").rglob("*.ino")))

print("=" * 40)
print("Arduino (.ino) File Counter")
print("=" * 40)
print(f"Total .ino files found: {count}")
print("=" * 40)
