from typing import List


MULTIPLIER = 0x5DEECE66D
ADDEND = 0xB
MASK = (1 << 48) - 1

MODULO = 1000
RIGHT_SHIFT = 17


def update_seed(seed: int) -> int:
    return (seed * MULTIPLIER + ADDEND) & MASK

def next_int(seed: int, n: int = MODULO) -> int:
    return (seed >> RIGHT_SHIFT) % n

def solution(nums: List[int]) -> List[int]:
    for lower_bits in range(2 ** 20):
        is_all_match = True
        seed = lower_bits
        for value in nums:
            seed = update_seed(seed)
            if (next_int(seed) & 7) != (value & 7):
                is_all_match = False
                break
        if not is_all_match:
            continue

        for higher_bits in range(2 ** 28):
            is_all_match = True
            seed = (higher_bits << 20) | lower_bits
            for value in nums:
                seed = update_seed(seed)
                if (next_int(seed) != value):
                    is_all_match = False
                    break
            if is_all_match:
                remaining_nums = []
                for _ in range(10):
                    seed = update_seed(seed)
                    remaining_nums.append(next_int(seed))
                return remaining_nums

    return []

def main():
    num_inputs = [list(map(int, input().split())) for _ in range(int(input()))]
    for nums in num_inputs:
        print(" ".join(map(str, solution(nums))))

main()
