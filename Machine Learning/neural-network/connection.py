LEARNING_RATE = 5

class connection():

    def __init__(self, weight: float) -> None:
        self.weight_ = weight

    def set_input(self, val: float) -> None:
        self.input_ = val

    def set_delta(self, val: float) -> None:
        self.delta_ = val

    def get_output(self) -> float:
        return self.input_ * self.weight_

    def get_delta(self) -> float:
        return self.delta_ * self.weight_
    
    def update(self) -> None:
        self.weight_ += LEARNING_RATE * self.delta_ * self.input_ 