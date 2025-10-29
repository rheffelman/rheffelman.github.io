# Background
*Catenary*, from Latin *catena* meaning "chain, fetter, shackle" (cognate with "Chain", and "Concatenate"). In Mathematics, "Catenary" refers to the curve that an idealized hanging chain or cable assumes under its own weight when supported only at its ends in a uniform gravitational field. ([For more info, see the Wikipedia](https://en.wikipedia.org/wiki/Catenary))

![Alt text](./SURE/image.png)
![Alt text](./SURE/500px-SpiderCatenary.jpg)

Generally, the catenary shape is defined by $y = a \cosh(\frac{x}{a})$, where $a$ is the distance between the x-axis and the lowest point of the curve.

### The Problems:
**Forward problem:** Given a density function of a cable and its endpoints, what is the shape made by it when hung?

**Inverse problem:** Given a shape, what is the density function of the cable?

# My Work
Using a Python program we wrote that solves the forward problem, I generated tens of thousands of catenaries using with random parameters, such as length, density functions, and endpoints.

![Alt text](./SURE/cats.png)
![Alt text](./SURE/veri.png)

Using a convolutional neural network that takes in many y-points evenly distributed along the arc length/shape of a catenary, and outputs it's guesses for the density at each point.

![Alt text](./SURE/diagram.png)
![Alt text](./SURE/dens.png)

The model did a pretty good job at guessing data, *a lot* better than humans can do intuitively, it's overall loss got down to 0.37, which is decent, but a lot worse than you'd expect given that we can fabricate as much training data as we want. This is because it attempts to solve a technically impossible problem.

It's impossible because mapping a shape function onto a density function is injective, so $f: s(x) \rightarrow d(x)$ is injective meaning that 1 shape can have multiple possible density functions. For example, $(d(x) \rightarrow s(x))$ implies $(c \cdot d(x) \rightarrow s(x))$ where $c$ is any positive scalar, $d(x)$ is the density function along the arc length, $s(x)$ is the shape function along the arc length, and $\rightarrow$ is an operation mapping 1 function onto another. It is impossible to find *which* $d(x)$ that $s(x)$ maps to without a sense of scale. It is however possible to find which *kind* of density function maps onto a given shape, when scaled properly.
![Alt text](./SURE/parent_dens.png)

Additionally, we are able to start with a shape of some catenary, and find which parent density function would create that shape. For example, here's what density function you'd need to create a curve with the shape $y = -\sin(x)$.
![Alt text](./SURE/sin_dens.png)