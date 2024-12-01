# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_hexdump.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 20:07:43 by thitoe            #+#    #+#              #
#    Updated: 2024/09/23 04:25:46 by thitoe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# テスト結果を保持する変数
PASS=0
FAIL=0

# テスト関数
run_test() {
  # 一時ファイルのパス
  expected_file=$(mktemp)
  output_file=$(mktemp)
  expected_stripped_file=$(mktemp)
  output_stripped_file=$(mktemp)

  # テストの結果をファイルに出力
  eval "$1 2>&1" > "$expected_file"
  eval "$2 2>&1" > "$output_file"

  # 出力から 'hexdump' と 'ft_hexdump' を取り除く
  sed 's/hexdump: //' "$expected_file" > "$expected_stripped_file"
  sed 's/ft_hexdump: //' "$output_file" > "$output_stripped_file"

  # 比較して結果を表示
  if diff -u "$expected_stripped_file" "$output_stripped_file" > /dev/null; then
    echo "PASS: $2"
    cat "$expected_file"
    PASS=$((PASS+1))
  else
    echo "FAIL: $2"
    echo "Diff:"
    diff -u "$expected_stripped_file" "$output_stripped_file"
    FAIL=$((FAIL+1))
  fi

  # 一時ファイルの削除
  rm -f "$expected_file" "$output_file" "$expected_stripped_file" "$output_stripped_file"
}
# 各テストケースを実行
echo "Creating test data..."

# テストデータ作成
echo -n "This is a test file for hexdump." > testfile.txt
echo -n "Small file." > smallfile.txt
echo -n "First file content." > file1.txt
echo -n "Second file content." > file2.txt
echo -n "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" > file3.txt
echo -n "aaaaabbbbbbbceeiajfieonjaflenf;aliehnfoeanefoiano;ifne;anfdkjbaclhadbicpszofiac;ejca;lencoa;bjec;akejbv;ljdalcnl;adjbvkjadnl;vcan;lfa" > file4.txt

# テストケース1: 通常の hexdump 表示
echo "test1"
run_test "hexdump testfile.txt" "./ft_hexdump testfile.txt"
echo ""

# テストケース2: -C オプションを使った表示
echo "test2"
run_test "hexdump -C testfile.txt" "./ft_hexdump -C testfile.txt"
echo ""

# テストケース3: 小さいファイルを表示
echo "test3"
run_test "hexdump smallfile.txt" "./ft_hexdump smallfile.txt"
echo ""

# テストケース4: -C オプションで小さいファイルを表示
echo "test4"
run_test "hexdump -C smallfile.txt" "./ft_hexdump -C smallfile.txt"
echo ""

# テストケース5: 複数ファイルのテスト
echo "test5"
run_test "hexdump file1.txt file2.txt" "./ft_hexdump file1.txt file2.txt"
echo ""

# テストケース6: -C オプションで複数ファイルのテスト
echo "test6"
run_test "hexdump -C file1.txt file2.txt" "./ft_hexdump -C file1.txt file2.txt"
echo ""

# テストケース7: 存在しないファイルのテスト
echo "test7"
run_test "hexdump non_existent.txt" "./ft_hexdump non_existent.txt"
echo ""

# テストケース8: 標準入力からのテスト
echo "test8"
run_test "echo 'abcdefghijk' | hexdump -C" "echo 'abcdefghijk' | ./ft_hexdump -C"
echo ""

echo "test9"
# テストケース9: ディレクトリ指定によるエラーメッセージのテスト
run_test "hexdump ."  "./ft_hexdump ."
echo ""

echo "test10"
run_test "hexdump a"  "./ft_hexdump a"
echo ""

echo "test11"
run_test "hexdump a b"  "./ft_hexdump a b"
echo ""

echo "test12"
run_test "hexdump a ."  "./ft_hexdump a ."
echo ""

echo "test13"
run_test "hexdump file3.txt" "./ft_hexdump file3.txt"
echo ""

echo "test14"
run_test "hexdump -C file3.txt" "./ft_hexdump -C file3.txt"
echo ""

echo "test15"
run_test "hexdump test/file4.txt test/file4.txt generated4.test generated5.test" "./ft_hexdump test/file4.txt test/file4.txt generated4.test generated5.test"
echo ""

echo "test16"
run_test "hexdump -C test/file4.txt test/file4.txt generated4.test generated5.test" "./ft_hexdump -C test/file4.txt test/file4.txt generated4.test generated5.test"
echo ""

echo "test17"
run_test "hexdump test/file4.txt test/file4.txt . ." "./ft_hexdump test/file4.txt test/file4.txt . ."
echo ""

echo "test18"
run_test "hexdump -C test/file4.txt test/file4.txt . ." "./ft_hexdump -C test/file4.txt test/file4.txt . ."
echo ""

echo "test19"
run_test "hexdump test/test2 test/test2 . ." "./ft_hexdump test/test2 test/test2 . ."
echo ""

echo "test20"
run_test "hexdump test/test2 test/test2 generated4.test generated5.test" "./ft_hexdump test/test2 test/test2 generated4.test generated5.test"
echo ""

# テストファイル削除
echo "Cleaning up test data..."
rm -f testfile.txt smallfile.txt file1.txt file2.txt file3.txt file4.txt file5.txt

# テスト結果の集計
echo "Tests passed: $PASS"
echo "Tests failed: $FAIL"

if [ $FAIL -eq 0 ]; then
  echo "すべてのテストが成功しました！"
else
  echo "$FAIL 個のテストが失敗しました。"
fi

