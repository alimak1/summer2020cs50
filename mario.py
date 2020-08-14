from cs50 import get_int

while True:
    # input height of pyrmid
    h = get_int('Height: ')
    if h >= 1 and h <= 8:
        break
# for the length of height print height - i - 1 amount of of spaces followed by i + 1 about of #
# for example is h is 4, line on would have 3 spaces (4 - 0 - 1) and 1 hash (0 + 1)
for i in range(h):
    for j in range(h - i - 1):
        print(' ', end='')
    for k in range(i + 1):
        print('#', end='')
    print()
