class Solution {
public:
 int square(int num){
    int ans=0;
    while(num>0){
        int rem=num%10;
        ans+=rem*rem;
        num/=10;
    }
  return ans;
 }
    bool isHappy(int n) {
        int fast=n;
        int slow=n;
        do{
            slow=square(slow);
            fast=square(square(fast));

            
        }while(slow!=fast);
        return slow==1;
        
        
    }
};