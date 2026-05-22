class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(arr[mid]==target){
                return mid;
            }

            //check the left part is sorted or not

            if(arr[low]<=arr[mid]){

                //check the target value lies on that left sorted part or not if yes then move
                // towards left part otherwise on the right part
                if(target>=arr[low] && target <=arr[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                //similarly here we also check that target lies in the right sorted part or 
                // or not if it lies or right sorted part then move towards left part otherwise
                // move towards left part
                if(target>=arr[mid] && target<=arr[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            mid=low+(high-low)/2;
        }
        return -1;
    }
};