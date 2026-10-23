template <typename T>
T DynamicArray<T>::countAdditionElement(T a, T b) {
    if constexpr (std::is_arithmetic_v<T>) {
        constexpr int PERIOD = MAX_VALUE - MIN_VALUE + 1;   // 201
        double s   = static_cast<double>(a) + static_cast<double>(b);
        double off = std::fmod(s - MIN_VALUE, static_cast<double>(PERIOD));
        if (off < 0) off += PERIOD;
        return static_cast<T>(MIN_VALUE + off);
    } else {
        throw std::bad_typeid();
    }
}

template <typename T>
T DynamicArray<T>::countSubtractionNumber(T a, T b) {
    if constexpr (std::is_arithmetic_v<T>) {
        constexpr int PERIOD = MAX_VALUE - MIN_VALUE + 1;
        double d   = static_cast<double>(a) - static_cast<double>(b);
        double off = std::fmod(d - MIN_VALUE, static_cast<double>(PERIOD));
        if (off < 0) off += PERIOD;
        return static_cast<T>(MIN_VALUE + off);
    } else {
        throw std::bad_typeid();
    }
}

template <typename T>
void DynamicArray<T>::isValueInRange(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        if (value < MIN_VALUE || value > MAX_VALUE) {
            throw std::invalid_argument("Invalid argument");
        }
    }
}

template <typename T>
void DynamicArray<T>::isIndexValid(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index");
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(int array_size) {
    if (array_size < 0) array_size = 0;
    size = array_size;
    capacity = array_size;
    data = new T[capacity]{};
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity]{};
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::set(int index, const T& value) {
    isValueInRange(value);
    isIndexValid(index);
    data[index] = value;
}

template <typename T>
T DynamicArray<T>::get(int index) {
    isIndexValid(index);
    return data[index];
}

template <typename T>
void DynamicArray<T>::pushBack(const T& value) {
    isValueInRange(value);

    if (size >= capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[new_capacity]{};

        if constexpr (std::is_trivially_copyable_v<T>) {
            std::memcpy(new_data, data, size * sizeof(T));
        } else {
            for (int i = 0; i < size; ++i) new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[size] = value;
    ++size;
}

template <typename T>
void DynamicArray<T>::print() {
    std::cout << "Array: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i + 1 < size) {
            std::cout << ", ";
        }
    }
    std::cout << " ]\n";
}

template <typename T>
void DynamicArray<T>::add(const DynamicArray<T>& other) {
    for (int i = 0; i < size; ++i) {
        T other_value = T{};
        if (i < other.size) other_value = other.data[i];
        data[i] = countAdditionElement(data[i], other_value);
    }
}

template <typename T>
void DynamicArray<T>::subtract(const DynamicArray<T>& other) {
    for (int i = 0; i < size; ++i) {
        T other_value = T{};
        if (i < other.size) other_value = other.data[i];
        data[i] = countSubtractionNumber(data[i], other_value);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
    os << "[ ";
    for (int i = 0; i < arr.size; ++i) {
        os << arr.data[i];
        if (i + 1 < arr.size) os << ", ";
    }
    os << " ]";
    return os;
}

template <typename T>
double distance(const DynamicArray<T>& a, const DynamicArray<T>& b) {
    if constexpr (!std::is_arithmetic_v<T>) {
        throw std::bad_typeid();
    } else {
        if (a.size != b.size) {
            throw std::invalid_argument("Array sizes must be equal");
        }
        double sum = 0.0;
        for (int i = 0; i < a.size; ++i) {
            double diff = static_cast<double>(a.data[i]) - static_cast<double>(b.data[i]);
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }
}