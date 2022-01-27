class Solution {
public:
	void fill(vector<vector<int>>& image, int sr, int sc, int origColor, int newColor) {
		// bounds check
		if ( sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ) return;

		// change pixel
		if (image[sr][sc] != origColor) return;
		image[sr][sc] = newColor;

		// recursion on directional neighbors
		fill(image, sr - 1, sc, origColor, newColor);
		fill(image, sr, sc - 1, origColor, newColor);
		fill(image, sr + 1, sc, origColor, newColor);
		fill(image, sr, sc + 1, origColor, newColor);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int origColor = image[sr][sc];
		// Infinite recursion will lead to stack overflow without this if statement
		if (origColor != newColor)
			fill(image, sr, sc, origColor, newColor);
		return image;
	}
};

class Solution {
public:
	void call(vector<vector<int>>& image, int i, int j, int newColor, int n, int m, int oddColor) {

		if (i < 0 or j < 0) return;
		if (i >= n or j >= m) return;

		if (image[i][j] == newColor) return; //already done

		if (image[i][j] != oddColor) return; //diff color


		if (image[i][j] == oddColor)
			image[i][j] = newColor; //visited mark

		call(image, i + 1, j, newColor, n, m, oddColor);
		call(image, i - 1, j, newColor, n, m, oddColor);
		call(image, i, j + 1, newColor, n, m, oddColor);
		call(image, i, j - 1, newColor, n, m, oddColor);
	}



	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int oddColor = image[sr][sc];
		call(image, sr, sc, newColor, image.size(), image[0].size(), oddColor);
		return image;
	}
};
