# Monte-Carlo-Simulation-for-Option-Pricing

This project used the essence of the Monte Carlo method that we carry out a simulation experiment by finding the solution of a stochastic differential equation (SDE) from time t = 0 to time t = T. This process allows us to compute the stock price at t = T and then the option price using the payoff function. We carry out M simulations or draws by finding the solution of the SDE and we calculate the option price at t = T. Finally, we calculate the discounted average of the simulated payoff and we are done.

In this project, I tried to program the MC simulation using all the resources from other libraries and I created a generic function to compute the standard deviation and standard error into the MC simulation program, making it more advanced. The inputs are NT (time steps) and NSIM (simulations or draws) and it returns a numerically approximation of a option prices. By doing this, I am able to understand how the option prices converge with different values of NT and NSIM while at the same time tackle with the accuracy of MC simulation. 
