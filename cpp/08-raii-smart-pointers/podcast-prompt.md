# Podcast 08 — RAII와 Smart Pointer

## 학습 자료

- [RAII / unique_ptr](https://modoocode.com/229)
- [shared_ptr / weak_ptr](https://modoocode.com/252)

## 팟캐스트 프롬프트

> C의 `malloc/free`와 C++의 `new/delete`를 아는 개발자에게 RAII와 Smart Pointer를 설명해주세요. 수동 메모리 관리에서 memory leak, double free, 예외 상황이 왜 문제가 되는지부터 시작해 RAII가 이를 어떻게 해결하는지 알려주세요. `unique_ptr`, `shared_ptr`, `weak_ptr`을 문법보다 ownership과 lifetime 관점에서 설명하고, unique/shared ownership의 차이와 `weak_ptr`의 필요성을 분명히 해주세요. 현대 C++에서 `new/delete` 직접 사용보다 RAII가 권장되는 이유로 마무리해주세요.

