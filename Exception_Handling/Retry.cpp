#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime, bool throwLast)  {
    int cnt = 0;

    while (cnt < retryCount + 1) {
        try {
            return func();
        } catch (const Exception&) {
                // значит еще есть попытки           
                if (cnt == retryCount) {
                    if (throwLast == true) {
                        throw;
                    }
                } else {
                    Sleep(sleepTime);
                    cnt++;
                }
        }
    }
    return {};
}



