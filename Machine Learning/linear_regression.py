import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics



# simple linear regression

# least squares method for linear regression
# squares being the difference between actuall va

x = np.array([5, 15, 25, 35, 45, 55])
y = np.array([5, 20, 14, 32, 22, 38])

# avg of elements in arrays x and y
x_mean = np.mean(x)
y_mean = np.mean(y)

# difference of each element in array with the array avg
x_diff = x - x_mean
y_diff = y - y_mean
x_diff_squared = x_diff ** 2

# slope of the regression line - b1
m = np.sum(x_diff * y_diff) / np.sum(x_diff_squared)

# interception of y axis by the regression line - b0
b = y_mean - m * x_mean

# simple linear regression - f(x) = b0 + b1 * x
def predict(x):
    return b + m * x

# function to create a graph
def plot_regression_line(x, y, b):
    # plotting the actual points as scatter plot
    plt.scatter(x, y, color = "m",
               marker = "o", s = 30)
 
    # predicted response vector
    y_pred = b[0] + b[1]*x
 
    # plotting the regression line
    plt.plot(x, y_pred, color = "g")
 
    # putting labels
    plt.xlabel('x')
    plt.ylabel('y')
 
    # function to show plot
    plt.show()


# plot_regression_line(x, y, (b, m))

# linear regression using libraries


dataset = pd.read_csv("C:/Users/jakub/Desktop/ForFunProjects/Machine Learning/winequality-white.csv", sep=';')
print(dataset.shape)
print(dataset.describe())

dataset.plot(x='fixed acidity', y='quality', style='o')
plt.title('Wine Fixed Acidity vs Wine Quality')
plt.xlabel('Fixed Acidity')
plt.ylabel('Quality')
plt.show()

X = dataset['fixed acidity'].values.reshape(-1,1)
y = dataset['quality'].values.reshape(-1,1)

#spliting samples - 19% for test, 81% for training
X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=0.19, random_state=0)

# fitting training data
regress = LinearRegression()
regress.fit(X_train, y_train)

print('Intercept: ', regress.intercept_)
print('Coefficient: ', regress.coef_)

y_prediction = regress.predict(X_test)

dataFrame = pd.DataFrame({'Actuall value': y_test.flatten(), 'Predicted value': y_prediction.flatten()})
print(dataFrame)


# differences data frame chart
df = dataFrame.head(40)
df.plot(kind='bar', figsize=(16,10))
plt.grid(which='major', linestyle='-', linewidth='0.5', color='green')
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.show()

plt.scatter(X_test, y_test, color='lightblue')
plt.plot(X_test, y_prediction, color='red', linewidth=2.5)
plt.show()

print('Mean abs error: ', metrics.mean_absolute_error(y_test, y_prediction))
print('Mean squared error:', metrics.mean_squared_error(y_test, y_prediction))
print('Root mean squared error:', np.sqrt(metrics.mean_squared_error(y_test, y_prediction)))
