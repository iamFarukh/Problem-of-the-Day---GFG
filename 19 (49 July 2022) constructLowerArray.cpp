typedef tree<
double,
null_type,
less_equal<double>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int> ans(n);
	    ordered_set X;
	    for(int i=n-1;i>=0;i--)
	    {
	        X.insert(arr[i]+0.1);
	        ans[i] = X.order_of_key(arr[i]);
	    }
	    return ans;
}
