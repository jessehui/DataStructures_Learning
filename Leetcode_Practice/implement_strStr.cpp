/*Implement strStr().

Returns the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.

*/

//strstr()函数用来检索子串在字符串中首次出现的位置，其原型为：
    char *strstr( char *str, char * substr );


//works well 73/74 Then TLE...
//after addding ***  Accepted
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle || needle == "")
        	return 0;
        for(int i = 0;i < haystack.size(); i++)
        {
        	if(haystack[i] == needle[0])	//equal
        	{
	        	int temp = i;
	        	int pos = 0;
	        	while(pos < needle.size() && haystack[temp] == needle[pos])
	        	{
	        		temp++; pos++;

	        	}

	        	if(pos == needle.size())
	        		return i;
	        }

			/* *** */	        
			if(i > haystack.size() - needle.size())	//
	        	return -1;
        }

        return -1;
    }
};

//
// "mississippi"
// "issip"
//test
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle || needle == "")
        	return 0;
        for(int i = 0;i < haystack.size(); i++)
        {
        	if(haystack[i] == needle[0])	//equal
        	{
	        	int temp = i;
	        	int pos = 0;
	        	while(pos < needle.size() && haystack[temp] == needle[pos])
	        	{
	        		temp++; pos++;

	        	}

	        	if(pos == needle.size())
	        		return i;
	        	// else
	       	 //    	i = temp;		//跳的话会出bug 比如上边那个输入情况
	        }
	        
			if(i > haystack.size() - needle.size())	//
	        	return -1;
        }

        return -1;
    }
};
