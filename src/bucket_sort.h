template<typename T>
void bucketSort(std::vector<T>& arr) {

    if (arr.empty()) return;

    long long n = arr.size();

auto maxValue = *std::max_element(arr.begin(), arr.end());
    auto minValue = *std::min_element(arr.begin(), arr.end());
    auto BUCKET_NUM = (maxValue-minValue)/n + 1;

    std::vector<std::vector<T>> buckets(BUCKET_NUM);
    for (auto num : arr) {
        auto bi = static_cast<long long>(num - minValue) / n;

        buckets[bi].push_back(num);
    }
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    int index = 0;
    for (auto& bucket : buckets) {
        for (auto num : bucket) {
            arr[index++] = num;
        }
    }
}
