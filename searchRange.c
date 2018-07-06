class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> v(2,-1);
        if(n < 1)
            return v;
        v[0] = BanarySearchLeft(A, n, target);
        v[1] = BanarySearchRight(A, n, target);
        return v;
    }
    int BanarySearchLeft(int A[], int n, int target)
    {
         int left = 0;
        int right = n;
        while(left < right)
        {
            int mid = left+((right-left)>>1);
            if(A[mid] == target && (mid == 0 || A[mid-1]<target))
                return mid;
            else if(A[mid] < target)
                left = mid+1;
            else
                right = mid;
        }
        return -1;
    }
        int BanarySearchRight(int A[], int n, int target)
    {
         int left = 0;
        int right = n;
        while(left < right)
        {
            int mid = left+((right-left)>>1);
            if(A[mid] == target && (mid == n-1 || A[mid+1]>target))
                return mid;
            else if(A[mid] > target)
                right = mid;
            else
                left = mid+1;
        }
        return -1;
    }
};
