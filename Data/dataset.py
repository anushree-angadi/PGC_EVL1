
import sys

if len(sys.argv) != 3:
    print("Usage: python3 data/generate_dataset.py SIZE OUTPUT_FILE")
    print("Example: python3 data/generate_dataset.py 100000 data/dataset.txt")
    sys.exit(1)

size = int(sys.argv[1])
output_file = sys.argv[2]

if size not in (100000, 1000000, 10000000):
    print("Unsupported dataset size.")
    sys.exit(1)

with open(output_file, "w", encoding="utf-8") as file:
    for number in range(1, size + 1):
        file.write(f"{number}\n")

print(f"Generated {size} integers in {output_file}")
