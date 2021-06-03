# A little show of pride

A friend of mine, [Matteo Bonacini](https://github.com/P2-718na), coded a program that simulates the outbreak of a pandemic in a city using AI.<br> He asked me 
to fit the data collected by running his program, and check whether his program was in agreement with the logisic model.<br> I thought this could've been a good 
benchmark to check the concreteness of my code.<br> This is the output of my program (I fitted until the day 40 of his data and asked the program for prediction 
of day 45):

	An initial guess was found:
	K(0) = 322.5 A(0) = 99.324 r(0) = 0.11053
	The series converged after 959 iterations
	Estimated parameters:
	K = 321.449| A = 99.3743| r = 0.10991
	The maximum daily cases day was day 41.8423 from the data day one
	Variance = 38.0823
	Total cases expected at day 45 from the first day of the data = 188.339


As you can see, the program worked very well and it had its job done.<br> The variance is very small, leading to a percentage error of 0.6 %. This means that 
either his code and mine are both wrong, either they're both right. Moreover, the prediction for the 45th day was of 188 cases, while the data showed 184 cases, 
a number fully compatible in the range +/- 6 cases (The square root of the variance).
