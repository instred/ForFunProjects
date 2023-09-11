
from neural_network import neural_network


TOPOLOGY = [784,28,28,10]


def testing() -> None:
    nn = neural_network(TOPOLOGY)
    with open("mnist_train.csv", "r") as file:
        for i in range(0, 1000):
            img = file.readline().replace("\n", "")
            pixels = [int(pix) for pix in img.split(",")]
            
            expected = pixels.pop(0)
            fpixels = [float(pix/ 255.0) for pix in pixels]
            
            pout = [
                0.0, 
                0.0,
                0.0, 
                0.0,
                0.0, 
                0.0,
                0.0, 
                0.0,
                0.0, 
                0.0,
            ]
            pout[expected] = 1.0
            nn.forward(fpixels)
            nn.backward(pout)
            dct = nn.get_output()
            max = 0.0
            max_key = ""
            for key, val in dct.items():
                if val > max:
                    max = val
                    max_key = key


            print(f"IMG number {i} expected = {expected} actual = {max_key}")



if __name__ == "__main__":
    testing()