# Podcast 05 — Template 기초: 타입이 달라도 같은 코드를 사용하기

- [팟캐스트 링크](직접 입력)

## 학습 자료

- [씹어먹는 C++ — 코드를 찍어내는 틀, C++ 템플릿](https://modoocode.com/219)

## 학습 목표

- 타입만 다른 중복 코드가 왜 문제인지 설명할 수 있다.
- 함수 템플릿과 클래스 템플릿을 읽고 사용할 수 있다.
- `std::vector<int>`, `std::map<std::string, int>` 표기를 해석할 수 있다.

# 1. 타입만 다르고 동작은 같은 코드

다음 두 함수는 자료형만 다르고 알고리즘은 같다.

```cpp
int Max(int a, int b) {
    return a > b ? a : b;
}

double Max(double a, double b) {
    return a > b ? a : b;
}
```

지원할 타입이 늘 때마다 함수를 복사하면 코드 중복도 늘어난다. 버그를 고칠 때 모든 버전을 함께 수정해야 한다는 문제도 생긴다.

# 2. 함수 템플릿

템플릿은 **타입을 인자로 받아 실제 함수나 클래스를 만들어 내는 틀**이다.

```cpp
#include <iostream>
#include <string>

template <typename T>
T Max(const T& a, const T& b) {
    return a > b ? a : b;
}

int main() {
    std::cout << Max(3, 7) << '\n';             // T는 int
    std::cout << Max(2.5, 1.5) << '\n';         // T는 double
    std::cout << Max<std::string>("A", "B") << '\n';
}
```

`Max(3, 7)`을 보면 컴파일러가 두 인자의 타입으로 `T == int`를 추론한다. 이후 `int`에 맞는 `Max<int>`를 생성한다. 이를 **템플릿 인스턴스화**라고 한다.

```mermaid
flowchart LR
    A["함수 템플릿 Max<T>"] --> B["Max(3, 7)"]
    B --> C["T = int 추론"]
    C --> D["Max<int> 생성"]
```

## 2.1 템플릿은 아무 타입에서나 무조건 동작하지 않는다

`Max` 내부에서는 `a > b`를 사용한다. 따라서 `T`는 `>` 비교가 가능한 타입이어야 한다. 템플릿이 요구하는 연산을 지원하지 않는 타입을 넣으면 해당 템플릿이 인스턴스화될 때 컴파일 오류가 난다.

## 2.2 타입 추론이 애매한 경우

```cpp
Max(3, 4.5);          // ❌ T를 int와 double 중 하나로 정할 수 없음
Max<double>(3, 4.5);  // ✅ T를 명시
```

# 3. 클래스 템플릿

같은 자료구조에 여러 타입을 담고 싶을 때 클래스 템플릿을 사용한다.

```cpp
#include <iostream>
#include <string>

template <typename T>
class Box {
private:
    T value_;

public:
    explicit Box(const T& value) : value_(value) {}

    const T& value() const {
        return value_;
    }
};

int main() {
    Box<int> score(95);
    Box<std::string> message("hello");

    std::cout << score.value() << '\n';
    std::cout << message.value() << '\n';
}
```

`Box<int>`와 `Box<std::string>`은 같은 틀에서 만들어지지만 서로 다른 타입이다.

| 코드 | 의미 |
|---|---|
| `template <typename T>` | 아래 선언에서 사용할 타입 매개변수 `T`를 정의 |
| `Box<T>` | 아직 타입이 결정되지 않은 클래스 틀 |
| `Box<int>` | `T`가 `int`인 실제 클래스 |
| `Box<std::string>` | `T`가 `std::string`인 실제 클래스 |

# 4. 템플릿과 STL의 연결

STL 컨테이너는 템플릿으로 만들어졌기 때문에 같은 자료구조를 여러 타입에 재사용할 수 있다.

```cpp
#include <map>
#include <string>
#include <vector>

std::vector<int> scores;                    // int를 저장하는 동적 배열
std::vector<std::string> names;              // string을 저장하는 동적 배열
std::map<std::string, int> ages;             // key는 string, value는 int
```

`vector`, `map` 사용자는 내부 구현을 다시 만들 필요 없이 `<>` 안에 필요한 타입만 전달한다. 따라서 템플릿은 STL의 문법적 기반이다.

# 5. 이번 단계에서 기억할 범위

지금은 다음만 이해하면 충분하다.

1. 템플릿은 타입을 받는 코드의 틀이다.
2. 함수 템플릿은 타입만 다른 함수 중복을 줄인다.
3. 클래스 템플릿은 동일한 구조를 여러 타입에 적용한다.
4. 실제 코드는 필요한 타입으로 인스턴스화될 때 만들어진다.
5. 템플릿도 내부에서 사용하는 연산을 해당 타입이 지원해야 한다.

템플릿 특수화, 가변 템플릿, 템플릿 메타 프로그래밍은 이번 학습 범위에서 제외한다.

## 복습 문제

### 문제 1 — 함수 템플릿 구현

두 값을 받아 더한 결과를 반환하는 `Add<T>`를 작성하고 `int`, `double`, `std::string`으로 시험하라. 각 타입에서 `+`가 어떤 의미인지 설명하라.

### 문제 2 — 컴파일 오류 찾기

다음 코드가 왜 컴파일되지 않는지 설명하고 두 가지 수정 방법을 작성하라.

```cpp
std::cout << Max(10, 20.5) << '\n';
```

### 문제 3 — 클래스 템플릿 구현

두 값을 저장하고 더 큰 값을 반환하는 `Pair<T>` 클래스를 작성하라.

### 문제 4 — STL 표기 해석

`std::map<std::string, std::vector<int>>`가 저장하는 데이터의 구조를 말로 설명하고 간단한 사용 예를 작성하라.

## 한 줄 요약

> **Template은 타입만 다른 동일한 코드를 하나의 틀로 만들고, STL이 여러 타입을 다룰 수 있게 하는 기반이다.**
