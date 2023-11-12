class Solution {

    public int subsets(int[] nums, int index, ArrayList<Integer> list, ArrayList<ArrayList<Integer>> sub)
    {
        if(index == nums.length)
        {   
            int subxor = 0;
            for(int i=0; i<list.size(); i++)
            {
                subxor = (subxor^list.get(i));
            }
            return subxor;
        }

        int sum1 = subsets(nums, index+1, list, sub);
        list.add(nums[index]);
        int sum2 = subsets(nums, index+1, list, sub);
        return sum1 + sum2;
    } 
    public int subsetXORSum(int[] nums) 
    {
        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<ArrayList<Integer>> sub = new ArrayList<>();
        return subsets(nums, 0, list, sub);
    }
}