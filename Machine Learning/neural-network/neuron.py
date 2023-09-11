from connection import connection
from random import uniform
import math

from typing import List

class neuron():

    def __init__(self, nlc: int = 0) -> None:
        self.in_weights_ = []
        self.out_weights_ = []
        self.input_ = 0.0
        for _ in range(0, nlc):
            self.out_weights_.append(connection(uniform(0.0, 1.0)))
        
    @staticmethod
    def activ_(x: float) -> float:
        return 1.0/(1.0 + math.exp(-x))
    
    @staticmethod
    def deriv_activ_(x: float) -> float:
        return neuron.activ_(x) * (1.0 - neuron.activ_(x))
    
    def forward(self) -> None:
        if len(self.in_weights_) > 0:
            self.input_ = 0.0
            for edge in self.in_weights_:
                self.input_ += edge.get_output()

        self.output_ = neuron.activ_(self.input_)

        if len(self.out_weights_) > 0:
            for edge in self.out_weights_:
                edge.set_input(self.output_)

    def backward(self) -> None:
        if len(self.out_weights_) > 0:
            self.delta_ = 0.0
            for edge in self.out_weights_:
                self.delta_ += edge.get_delta()
            
            self.delta_ *= neuron.deriv_activ_(self.input_)

        if len(self.in_weights_) > 0:
            for edge in self.in_weights_:
                edge.set_delta(self.delta_)

    def set_delta(self, goal: float) -> None:
        self.delta_ = neuron.deriv_activ_(self.input_) * (goal - self.output_)

    def update(self) -> None:
        if len(self.in_weights_) > 0:
            for edge in self.in_weights_:
                edge.update()

    def set_input(self, input: float = 1.0) -> None:
        self.input_ = input

    def set_in_weights(self, in_weights: List[connection]) -> None:
        self.in_weights_ = in_weights

    def get_out_weight(self, idx: int) -> connection:
        return self.out_weights_[idx]
 
    def get_output(self) -> float:
        return self.output_