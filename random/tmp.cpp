/* A dynamic programming based C++ program print 
shortest supersequence of two strings */
#include <bits/stdc++.h> 
using namespace std; 

// returns shortest supersequence of X and Y 
string printShortestSuperSeq(string X, string Y) 
{ 
	int m = X.length(); 
	int n = Y.length(); 

	// dp[i][j] contains length of shortest supersequence 
	// for X[0..i-1] and Y[0..j-1] 
	int dp[m + 1][n + 1]; 

	// Fill table in bottom up manner 
	for (int i = 0; i <= m; i++) 
	{ 
		for (int j = 0; j <= n; j++) 
		{ 
			// Below steps follow recurrence relation 
			if(i == 0) 
				dp[i][j] = j; 
			else if(j == 0) 
				dp[i][j] = i; 
			else if(X[i - 1] == Y[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1]; 
			else
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); 
			cout<<dp[i][j]<<" ";
		} 
		cout<<endl;
	} 

	// Following code is used to print shortest supersequence 

	// dp[m][n] stores the length of the shortest supersequence 
	// of X and Y 
	int index = dp[m][n]; 

	// string to store the shortest supersequence 
	string str; 

	// Start from the bottom right corner and one by one 
	// push characters in output string 
	int i = m, j = n; 
	while (i > 0 && j > 0) 
	{ 
		// If current character in X and Y are same, then 
		// current character is part of shortest supersequence 
		if (X[i - 1] == Y[j - 1]) 
		{ 
			// Put current character in result 
			str.push_back(X[i - 1]); 

			// reduce values of i, j and index 
			i--, j--, index--; 
		} 

		// If current character in X and Y are different 
		else if (dp[i - 1][j] > dp[i][j - 1]) 
		{ 
			// Put current character of Y in result 
			str.push_back(Y[j - 1]); 

			// reduce values of j and index 
			j--, index--; 
		} 
		else
		{ 
			// Put current character of X in result 
			str.push_back(X[i - 1]); 

			// reduce values of i and index 
			i--, index--; 
		} 
	} 

	// If Y reaches its end, put remaining characters 
	// of X in the result string 
	while (i > 0) 
	{ 
		str.push_back(X[i - 1]); 
		i--, index--; 
	} 

	// If X reaches its end, put remaining characters 
	// of Y in the result string 
	while (j > 0) 
	{ 
		str.push_back(Y[j - 1]); 
		j--, index--; 
	} 

	// reverse the string and return it 
	reverse(str.begin(), str.end()); 
	return str; 
} 

// Driver program to test above function 
int main() 
{ 
	string X = "geek"; 
	string Y = "kgeke"; 

	cout << printShortestSuperSeq(X, Y); 

	return 0; 
} 
