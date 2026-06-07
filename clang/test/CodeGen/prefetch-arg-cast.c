// RUN: %clang_cc1 -triple x86_64-pc-linux -emit-llvm %s -o - | FileCheck %s

void f() {
  __builtin_prefetch(0, 0 * sizeof(int), sizeof(int) / sizeof(int));
  // CHECK: call void @llvm.prefetch.p0(ptr null, i32 0, i32 1, i32 1)
}
