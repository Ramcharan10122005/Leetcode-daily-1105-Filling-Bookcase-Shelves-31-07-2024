int rec(int i,int** books,int s,int w,int* mem){
    if (i == s)
            return 0;
        if (mem[i] != -1)
            return mem[i];
        int cur_width = w;
        int max_height = 0;
        mem[i] = INT_MAX;
        for (int j = i; j < s; ++j) {
            int width = books[j][0], height = books[j][1];

            if (cur_width < width)
                break;

            cur_width -= width;
            max_height = fmax(max_height, height);
            mem[i] = fmin(mem[i], rec(j + 1, books,s, w, mem) + max_height);
        }
        return mem[i];
}
int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth) {
    int* mem=malloc(booksSize*sizeof(int));
    for(int i=0;i<booksSize;i++)
    mem[i]=-1;
    return rec(0,books,booksSize,shelfWidth,mem);
}
