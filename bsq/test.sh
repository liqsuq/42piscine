#!/bin/bash

# Perlのマップジェネレータースクリプトの内容
generate_map_script='
use warnings;
use strict;
die "Usage: program x y density\n" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y^+x\n"; # マップの行数とシンボル
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print "+";
        } else {
            print "^";
        }
    }
    print "\n";
}
'

# 繰り返し回数の指定（必要に応じて変更）
num_tests=100
correct_count=0  # 正解の回数をカウント
total_time=0  # 合計実行時間を計測

# テストをnum_tests回繰り返す
for (( i=1; i<=num_tests; i++ ))
do
    # ランダムなxとyを生成 (-1から1000まで)
    x=$(shuf -i 1-100 -n 1)  # xはマップの横幅
    y=$(shuf -i 1-100 -n 1)  # yはマップの高さ

    # 密度をランダムに指定 (1-10の範囲)
    density=$(shuf -i 1-10 -n 1)

    # 一時ファイルにマップを生成
    map_file="map_${i}.txt"
    perl -e "$generate_map_script" "$x" "$y" "$density" > "$map_file"
    
    echo "Running test #$i with map size ($x, $y), density $density"
    echo "Map generated and stored in $map_file"

    # 実行時間の計測開始
    start_time=$(date +%s.%N)

    # テストを実行し、出力をそのまま表示
    ./bsq "$map_file"

    # 実行時間の計測終了
    end_time=$(date +%s.%N)

    # 実行にかかった時間を計算
    elapsed_time=$(echo "$end_time - $start_time" | bc)
    total_time=$(echo "$total_time + $elapsed_time" | bc)

    # 出力をチェックして正解かどうか判定（"map error" が出ていなければ正解とする）
    if ./bsq "$map_file" | grep -q "map error"; then
        echo "Test #$i: Failed"
    else
        echo "Test #$i: Success"
        correct_count=$((correct_count + 1))  # 正解をカウント
    fi

    # 一時ファイルを削除
    # rm "$map_file"
    
    # 区切り表示
    echo "Execution time: ${elapsed_time}s"
    echo "-----------------------------"
done

# 最終的な正答率を表示
success_rate=$(echo "scale=2; ($correct_count / $num_tests) * 100" | bc)
average_time=$(echo "scale=3; $total_time / $num_tests" | bc)

echo "Test complete!"
echo "Correct tests: $correct_count out of $num_tests"
echo "Success rate: $success_rate%"
echo "Average execution time: ${average_time}s"
