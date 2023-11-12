class Solution {

    public void subsets(int[] nums, int index, ArrayList<Integer> list, ArrayList<ArrayList<Integer>> sub)
    {
        if(index == nums.length)
        {
            ArrayList<Integer> temp = new ArrayList<>(list);
            sub.add(temp);
            return;
        }

        list.add(nums[index]);
        subsets(nums, index+1, list, sub);
        list.remove(list.size() - 1);
        subsets(nums, index+1, list, sub);
    } 
    public int subsetXORSum(int[] nums) 
    {
        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<ArrayList<Integer>> sub = new ArrayList<>();
        subsets(nums, 0, list, sub);
        int res = 0;
        for(ArrayList<Integer> l : sub)
        {
            int subxor = 0;
            for(int i=0; i<l.size(); i++)
            {
                subxor = (subxor^l.get(i));
            }
            res+=subxor;
        }
        return res;
    }
}