/*
For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, 
use A to indicate the bulls and B to indicate the cows. In the above example, 
your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, 
for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, 
and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits,
and their lengths are always equal.
*/



class Solution {
public:
    string getHint(string secret, string guess) {
        multimap<char, int> dig_pos;	//digit - position
        for(int i = 0; i<secret.size(); i++)
        {
        	dig_pos.insert(make_pair(secret[i], i));
        }

        unordered_set<char> dig;
        int num_A = 0;	//bull
        int num_B = 0;	//cow
        for(int j = 0; j < guess.size(); j++)
        {
        	if(dig.count(guess[j]))
        		continue;
        	dig.insert[guess[j]];
        	if(dig_pos.count(guess[j]))	//if exist
        	{
        		//traverse all its corresponding key value to see whether there is a match
        		multimap<char, int>::iterator it;
        		for(it = dig_pos.equal_range(guess[j]).first; it != dig_pos.equal_range(guess[j].second; it++))
        		{
        			if(it->second == j)
        				num_A++;
        			else
        				num_B++;
        		}

        	}
        }

        cout << " A = " << A << endl;
        cout << " B = " << B << endl;


        string result = to_string(num_A) + A + to_string(num_B) + B;
        return result;
 

    }
};



class Solution {
public:
    string getHint(string secret, string guess) {
 	unordered_map<char, int> dig_num_secret;	//specific number has n numbers of digits
 	// unordered_map<char, int> dig_num_guess;
 	// for(int i = 0; i< secret.size(); i++)
 	// {
 	// 	dig_num_secret[secret[i]]++;
 	// }

 	for(int i = 0; i<secret.size();i++)
 	{
 		dig_num_secret[secret[i]]++;
 	}
 	int num_A = 0;
 	int num_B = 0;
 	for(int i = 0; i< secret.size(); i++)
 	{
 		if(secret[i] == guess[i])
 		{ 	
 		     num_A++;
 		     dig_num_secret[guess[i]]--;
 		}
//  		else
//  		{
//  			if(dig_num_secret[guess[i]] > 0)
//  			{
//  			    num_B++;
//  			    dig_num_secret[guess[i]]--;
//  			}
//  		}
 	}
 	
 	for(int i = 0; i < secret.size(); i++)
 	{
 	    if(secret[i] != guess[i])
 	    {
 	        if(dig_num_secret[guess[i]] > 0)
 			{
 			    num_B++;
 			    dig_num_secret[guess[i]]--;
 			}
 	    }
 	}

// 	cout << " A = " << num_A << endl;
//     cout << " B = " << num_B << endl;


    string result = to_string(num_A) + "A" + to_string(num_B) + "B";
    return result;

    }
};




