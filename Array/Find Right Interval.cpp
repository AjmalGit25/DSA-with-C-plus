vector<int> findRightInterval(vector<vector<int>>& intervals) {

    int n = intervals.size();

    vector<pair<int,int>> starts;

    // store {start, original_index}
    for (int i = 0; i < n; i++) {
        starts.push_back({intervals[i][0], i});
    }

    // sort by START
    sort(starts.begin(), starts.end());

    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {

        int target = intervals[i][1];

        int left = 0;
        int right = n - 1;

        int ans = -1;

        // binary search
        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (starts[mid].first >= target) {

                ans = starts[mid].second;

                // try finding smaller valid start
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        result[i] = ans;
    }

    return result;
}

/*

Find Right Interval

Goal:
	You must find the MINIMUM valid start.

Examples:
	A. 
		[[1,2],[3,4],[5,6]]
		
		For [1,2]:
			valid starts: 3, 5
		Need smallest: 3


*/