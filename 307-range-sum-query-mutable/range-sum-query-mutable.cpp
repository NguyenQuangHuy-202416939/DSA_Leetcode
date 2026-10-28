class NumArray {
private:
    int n;
    vector<int> tree;

    void build(vector<int>&nums, int id, int left, int right){
        if( left == right ){
            tree[id] = nums[left];
            return;
        }
        int mid = ( left + right) / 2;
        build(nums, id * 2 + 1, left, mid);
        build(nums, id * 2 + 2, mid + 1, right);
        tree[id] = tree[id*2+1] + tree[id*2+2];
    }

    void updateTree(int id, int left, int right, int index, int val){
        if( left == right){
            tree[id] = val;
            return;
        }
        int mid = ( left + right ) / 2;
        if( index <= mid){
            updateTree(id*2+1, left, mid, index, val);
        }
        else{
            updateTree(id*2+2, mid + 1, right, index, val);
        }
        tree[id] = tree[id*2+1] + tree[id*2+2];
    }

    int count_sum(int id, int left, int right, int start, int end){
        if(end < left || start > right){
            return 0;
        }
        if( start <= left && right <= end){
            return tree[id];
        }
        int mid = (left + right)/2;
        int sum_l = count_sum(id*2+1, left, mid, start, end);
        int sum_r = count_sum(id*2+2, mid + 1, right, start, end);
        return sum_l + sum_r;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n, 0);
        if( n > 0){
            build(nums, 0, 0 , n - 1);
        }
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n-1 ,index, val);
    }
    
    int sumRange(int left, int right) {
        return count_sum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */