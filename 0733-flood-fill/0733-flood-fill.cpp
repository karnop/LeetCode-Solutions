class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int originalColor, int color) {
    // Check boundary conditions and ensure the pixel has the original color.
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != originalColor) {
        return;
    }

    // Change the color of the current pixel.
    image[x][y] = color;

    // Call DFS on the 4 neighbors (up, down, left, right).
    dfs(image, x - 1, y, originalColor, color); // Up
    dfs(image, x + 1, y, originalColor, color); // Down
    dfs(image, x, y - 1, originalColor, color); // Left
    dfs(image, x, y + 1, originalColor, color); // Right
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor != color) {
            dfs(image, sr, sc, originalColor, color);
        }
        return image;
    }
};