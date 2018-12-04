from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 0 and height <= 23:
        break

# for each row
for i in range(height):

    # print spaces for left pyramid
    for j in range(height - (i + 1)):
        print(" ", end = "")

    # print hashes for left pyramid
    for j in range(i + 1):
        print("#", end = "")

    # print gap
    for j in range(2):
        print(" ", end = "")

    # print hashes for right pyramid
    for j in range(i + 1):
        print("#", end = "")

    # print new line
    print()
