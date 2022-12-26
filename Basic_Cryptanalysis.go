package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

type words struct {
	cipher []string
	clear  []string
}

var known = map[byte]byte{}

func main() {
	data, code := readData()
	maxLen := 0
	for k := range data {
		if maxLen < k {
			maxLen = k
		}
	}
	for i := maxLen; i > 1; i-- {
		ws := data[i]
		for _, c := range ws.cipher {
			m := match(c, ws.clear)
			if m != "" {
				updateKnown(c, m)
			}
		}
	}
	for i := range code {
		code[i] = decode(code[i])
	}
	fmt.Println(strings.Join(code, " "))
}

func match(cipher string, candidates []string) string {
	m := map[byte][]int{}
	for i := 0; i < len(cipher); i++ {
		m[cipher[i]] = append(m[cipher[i]], i)
	}
	var pCands []string
Next:
	for _, c := range candidates {
		for _, v := range m {
			for i := 1; i < len(v); i++ {
				if c[v[i]] != c[v[0]] {
					continue Next
				}
			}
		}
		for i := 0; i < len(cipher); i++ {
			if e, ok := known[cipher[i]]; ok && e != c[i] {
				continue Next
			}
		}
		pCands = append(pCands, c)
	}
	if len(pCands) == 1 {
		return pCands[0]
	} else {
		return ""
	}
}

func decode(cipher string) string {
	res := []byte(cipher)
	for i := range res {
		res[i] = known[res[i]]
	}
	return string(res)
}

func updateKnown(cipher, clear string) {
	if len(cipher) != len(clear) {
		panic("mismatch length")
	}
	for i := 0; i < len(cipher); i++ {
		if v, ok := known[cipher[i]]; ok && v != clear[i] {
			panic("invalid value")
		}
		known[cipher[i]] = clear[i]
	}
}

func readData() (map[int]*words, []string) {
	var s string
	var cipher []string
	_, err := fmt.Scan(&s)
	for err == nil {
		cipher = append(cipher, s)
		_, err = fmt.Scan(&s)
	}
	if err != io.EOF {
		panic(err)
	}
	dictionary, err := readLines("dictionary.lst")
	if err != nil {
		panic(err)
	}
	m := make(map[int]*words)
	for _, w := range cipher {
		if m[len(w)] == nil {
			m[len(w)] = new(words)
		}
		m[len(w)].cipher = append(m[len(w)].cipher, w)
	}
	for _, w := range dictionary {
		if m[len(w)] == nil {
			m[len(w)] = new(words)
		}
		m[len(w)].clear = append(m[len(w)].clear, w)
	}
	return m, cipher
}

func readLines(path string) ([]string, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var lines []string
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return lines, scanner.Err()
}
