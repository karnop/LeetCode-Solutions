class Solution {

    public void soln(String digits, ArrayList<String> keypad, String curr, ArrayList<String> result)
    {
        if(digits.isEmpty())
        {
            if(!curr.isEmpty())
                result.add(curr);
            return;
        }

        int dig = (int)digits.charAt(0)-(int)'0';
        for(int i=0; i<keypad.get(dig).length(); i++)
        {
            soln(digits.substring(1, digits.length()), keypad, curr+keypad.get(dig).charAt(i), result); 
        }
    }

    public List<String> letterCombinations(String digits) 
    {
        // String array for the keypad
        ArrayList<String> keypad = new ArrayList<>(Arrays.asList("", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"));

        // String array to store result
        ArrayList<String> result = new ArrayList<>();
        soln(digits, keypad, new String(), result);
        return result;   
    }
}