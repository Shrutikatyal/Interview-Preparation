//Leftmost set bit

while(n & n-1)
	n = n & n-1;
leftmost = log(n);

//Rightmost set bit
return log(n & -n)

