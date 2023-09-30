class Solution {

    public void soln(int n, int r, int lb, int rb, String curr, ArrayList<String> result)
    {
        // base case
        if(n == 0)
        {
            if(!curr.isEmpty())
                result.add(curr);
            return;
        }
        else if(curr.length() == 2*r)    return;

        if(curr.isEmpty())
            soln(n, r, lb+1, rb, curr+"(", result);
        
        else
        {
            if(lb>rb)
                soln(n-1, r, lb, rb+1, curr+")", result);

            soln(n, r, lb+1, rb, curr+"(", result);
        }
    }

    public List<String> generateParenthesis(int n) 
    {
        ArrayList<String> result = new ArrayList<>();
        soln(n, n, 0, 0, new String(), result);
        return result;
    }
}