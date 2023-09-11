from neural_network import neural_network
from random import randint

MAX = 4

TOPOLOGY = [2, MAX, MAX * 2 + 1]

def testing():
    nn = neural_network(TOPOLOGY)
    for i in range(0, 1000000):
        x = randint(0, MAX)
        y = randint(0, MAX)
        pout = [0.0 for _ in range(0, MAX * 2 + 1)]
        pout[x + y] = 1.0
        if i % 10000 == 0:
            print(f"Working {i / 10000} %")
        nn.forward([x/MAX, y/MAX])
        nn.backward(pout)

    while True:
        new_x = float(input("give X = "))
        new_y = float(input("give Y = "))

        nn.forward([new_x / MAX, new_y / MAX])

        print(f"{new_x} + {new_y} = {nn.get_output()}")
            


if __name__ == "__main__":
    testing()