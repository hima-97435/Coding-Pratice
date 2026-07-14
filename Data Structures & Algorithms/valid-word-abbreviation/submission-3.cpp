class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
           int n = word.size(), m = abbr.size();
        cout<<n<<" "<<m<<endl;
        int i=0, j=0;
        while(i<n && j<m){
        	
        	if(isalpha(abbr[j]) ) {
        		if(word[i] == abbr[j]) {i++;j++;}
        		else return false;
        	}
        	else {
        		if(abbr[j] == '0') return false;
        		int z =j;
        		while(j<m && isdigit(abbr[j])) j++;
        		// cout<<abbr.substr(z,j-z)<<endl;
        		i+=stoi(abbr.substr(z,j-z));
        	}
        	cout<<"i : "<<i<<" j: "<<j<<"\n";
        }

        return i == n && j == m; 
    }
};