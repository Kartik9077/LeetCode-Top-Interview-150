class Solution {
public:
  string  convert_to_required(string s){
    string required="";
    int n=s.length();
    for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            required+=s[i];
        }
        else if(isalpha(s[i])){
            if(islower(s[i])){
              required+=s[i];
            }
            else{
                char g=tolower(s[i]);
                required+=g;
            }
        
        }
        else{
            continue;
        }
    }
    return required;
  }
   bool check(string s1){
    int n=s1.size();
    int i=0,j=n-1;
    while(i<j){
        if(s1[i]==s1[j]){
            i++;j--;
        }
        else{
            return 0;
        }
    }
    return 1;

   }
   
    bool isPalindrome(string s) {
        string required=convert_to_required(s);
        return check(required);
        
    }
};