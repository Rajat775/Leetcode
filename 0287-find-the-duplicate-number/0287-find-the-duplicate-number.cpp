class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
//         int tortoise = nums[0];
//         int hare = nums[0];
        
//         while(tortoise!=hare)
//         {
//             hare=nums[nums[hare]];
//             tortoise=nums[tortoise];
//             if(hare==tortoise)
//                 break;
//         }
//         hare=nums[0];
//         while(tortoise!=hare)
//         {
//             hare=nums[nums[hare]];
//             tortoise=nums[tortoise];
//         }
//         return hare;
        
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};