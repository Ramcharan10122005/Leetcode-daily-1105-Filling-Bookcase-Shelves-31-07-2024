class Solution {
public:
    int rec(int i, vector<vector<int>>& books, int shelfWidth,
            vector<int>& mem) {
        if (i == books.size())
            return 0;
        if (mem[i] != -1)
            return mem[i];
        int cur_width = shelfWidth;
        int max_height = 0;
        mem[i] = INT_MAX;
        for (int j = i; j < books.size(); ++j) {
            int width = books[j][0], height = books[j][1];

            if (cur_width < width)
                break;

            cur_width -= width;
            max_height = max(max_height, height);
            mem[i] =
                min(mem[i], rec(j + 1, books, shelfWidth, mem) + max_height);
        }
        return mem[i];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> mem(n + 1, -1);
        return rec(0, books, shelfWidth, mem);
    }
};
