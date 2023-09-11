from typing import List
from neuron import neuron

class neural_network():

    def __init__(self, topology: List[int]) -> None:
        self.layers_ = []
        for idx in range(0, len(topology)):
            prev_layer = [] if len(self.layers_) == 0 else self.layers_[-1]
            layer = []
            for i in range(0, topology[idx]):
                layer.append(neuron(0 if idx == len(topology) - 1 else topology[idx + 1]))

                if prev_layer:
                    connections = []
                    for neu in prev_layer:
                        connections.append(neu.get_out_weight(i))
                    
                    layer[-1].set_in_weights(connections)

            if idx != len(topology) - 1:
                layer.append(neuron(0 if idx == len(topology) - 1 else topology[idx + 1]))
                layer[-1].set_input()
            
            self.layers_.append(layer)

    def forward(self, input: List[float]) -> None:
        for idx in range(0, len(input)):
            self.layers_[0][idx].set_input(input[idx])

        for layer in self.layers_:
            for neur in layer:
                neur.forward()


    def backward(self, predicted_output: List[float]) -> None:
        for pout, neur in zip(predicted_output, self.layers_[-1]):
            neur.set_delta(pout)

        for layer in list(reversed(self.layers_)):
            for neur in layer:
                neur.backward()
            
        for layer in self.layers_:
            for neur in layer:
                neur.update()

    def get_output(self) -> str:
        ret = dict()
        for val, neur in zip(range(0, len(self.layers_[-1])), self.layers_[-1]):
            ret[str(val)] = neur.get_output()

        return max(ret, key=ret.get)
            