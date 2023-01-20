/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int i=0,j=n-1;
        int maxi=-1;
        while(i<=j){
            if(i==0 && j==1){
                maxi=1;
                break;
            }
            else if(i==n-2 && j==n-1){
               maxi=n-2;
               break;
            }
            else{
                int mid=(j+i)/2;
                
                int x=mountainArr.get(mid-1);
                int y=mountainArr.get(mid);
                int z=mountainArr.get(mid+1);

                cout<<x<<" "<<y<<" "<<z<<endl;
                if(x<y && y>z){
                    maxi=mid;
                    break;
                }
                else if(x>y){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
        }

        cout<<maxi<<endl;
        int flag=-1;
        i=0;j=maxi;
        while(i<=j){
            int mid=(i+j)/2;
            int x=mountainArr.get(mid);
            if(x==target){
                flag=mid;
                break;
            }
            else if(x<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        
        if(flag!=-1){
            return flag;
        }

        i=maxi+1,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            int x=mountainArr.get(mid);
            if(x==target){
                flag=mid;
                break;
            }
            else if(x<target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        if(flag!=-1){
            return flag;
        }

        return -1;
    }
};
