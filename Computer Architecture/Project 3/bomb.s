
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000400b38 <_init>:
  400b38:	48 83 ec 08          	sub    $0x8,%rsp
  400b3c:	48 8b 05 b5 34 20 00 	mov    0x2034b5(%rip),%rax        # 603ff8 <__gmon_start__>
  400b43:	48 85 c0             	test   %rax,%rax
  400b46:	74 05                	je     400b4d <_init+0x15>
  400b48:	e8 f3 01 00 00       	callq  400d40 <__gmon_start__@plt>
  400b4d:	48 83 c4 08          	add    $0x8,%rsp
  400b51:	c3                   	retq   

Disassembly of section .plt:

0000000000400b60 <.plt>:
  400b60:	ff 35 a2 34 20 00    	pushq  0x2034a2(%rip)        # 604008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400b66:	ff 25 a4 34 20 00    	jmpq   *0x2034a4(%rip)        # 604010 <_GLOBAL_OFFSET_TABLE_+0x10>
  400b6c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400b70 <getenv@plt>:
  400b70:	ff 25 a2 34 20 00    	jmpq   *0x2034a2(%rip)        # 604018 <getenv@GLIBC_2.2.5>
  400b76:	68 00 00 00 00       	pushq  $0x0
  400b7b:	e9 e0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400b80 <strcasecmp@plt>:
  400b80:	ff 25 9a 34 20 00    	jmpq   *0x20349a(%rip)        # 604020 <strcasecmp@GLIBC_2.2.5>
  400b86:	68 01 00 00 00       	pushq  $0x1
  400b8b:	e9 d0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400b90 <__errno_location@plt>:
  400b90:	ff 25 92 34 20 00    	jmpq   *0x203492(%rip)        # 604028 <__errno_location@GLIBC_2.2.5>
  400b96:	68 02 00 00 00       	pushq  $0x2
  400b9b:	e9 c0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400ba0 <strcpy@plt>:
  400ba0:	ff 25 8a 34 20 00    	jmpq   *0x20348a(%rip)        # 604030 <strcpy@GLIBC_2.2.5>
  400ba6:	68 03 00 00 00       	pushq  $0x3
  400bab:	e9 b0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bb0 <puts@plt>:
  400bb0:	ff 25 82 34 20 00    	jmpq   *0x203482(%rip)        # 604038 <puts@GLIBC_2.2.5>
  400bb6:	68 04 00 00 00       	pushq  $0x4
  400bbb:	e9 a0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bc0 <write@plt>:
  400bc0:	ff 25 7a 34 20 00    	jmpq   *0x20347a(%rip)        # 604040 <write@GLIBC_2.2.5>
  400bc6:	68 05 00 00 00       	pushq  $0x5
  400bcb:	e9 90 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bd0 <__stack_chk_fail@plt>:
  400bd0:	ff 25 72 34 20 00    	jmpq   *0x203472(%rip)        # 604048 <__stack_chk_fail@GLIBC_2.4>
  400bd6:	68 06 00 00 00       	pushq  $0x6
  400bdb:	e9 80 ff ff ff       	jmpq   400b60 <.plt>

0000000000400be0 <alarm@plt>:
  400be0:	ff 25 6a 34 20 00    	jmpq   *0x20346a(%rip)        # 604050 <alarm@GLIBC_2.2.5>
  400be6:	68 07 00 00 00       	pushq  $0x7
  400beb:	e9 70 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bf0 <close@plt>:
  400bf0:	ff 25 62 34 20 00    	jmpq   *0x203462(%rip)        # 604058 <close@GLIBC_2.2.5>
  400bf6:	68 08 00 00 00       	pushq  $0x8
  400bfb:	e9 60 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c00 <read@plt>:
  400c00:	ff 25 5a 34 20 00    	jmpq   *0x20345a(%rip)        # 604060 <read@GLIBC_2.2.5>
  400c06:	68 09 00 00 00       	pushq  $0x9
  400c0b:	e9 50 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c10 <__libc_start_main@plt>:
  400c10:	ff 25 52 34 20 00    	jmpq   *0x203452(%rip)        # 604068 <__libc_start_main@GLIBC_2.2.5>
  400c16:	68 0a 00 00 00       	pushq  $0xa
  400c1b:	e9 40 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c20 <fgets@plt>:
  400c20:	ff 25 4a 34 20 00    	jmpq   *0x20344a(%rip)        # 604070 <fgets@GLIBC_2.2.5>
  400c26:	68 0b 00 00 00       	pushq  $0xb
  400c2b:	e9 30 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c30 <signal@plt>:
  400c30:	ff 25 42 34 20 00    	jmpq   *0x203442(%rip)        # 604078 <signal@GLIBC_2.2.5>
  400c36:	68 0c 00 00 00       	pushq  $0xc
  400c3b:	e9 20 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c40 <gethostbyname@plt>:
  400c40:	ff 25 3a 34 20 00    	jmpq   *0x20343a(%rip)        # 604080 <gethostbyname@GLIBC_2.2.5>
  400c46:	68 0d 00 00 00       	pushq  $0xd
  400c4b:	e9 10 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c50 <__memmove_chk@plt>:
  400c50:	ff 25 32 34 20 00    	jmpq   *0x203432(%rip)        # 604088 <__memmove_chk@GLIBC_2.3.4>
  400c56:	68 0e 00 00 00       	pushq  $0xe
  400c5b:	e9 00 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c60 <strtol@plt>:
  400c60:	ff 25 2a 34 20 00    	jmpq   *0x20342a(%rip)        # 604090 <strtol@GLIBC_2.2.5>
  400c66:	68 0f 00 00 00       	pushq  $0xf
  400c6b:	e9 f0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400c70 <malloc@plt>:
  400c70:	ff 25 22 34 20 00    	jmpq   *0x203422(%rip)        # 604098 <malloc@GLIBC_2.2.5>
  400c76:	68 10 00 00 00       	pushq  $0x10
  400c7b:	e9 e0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400c80 <fflush@plt>:
  400c80:	ff 25 1a 34 20 00    	jmpq   *0x20341a(%rip)        # 6040a0 <fflush@GLIBC_2.2.5>
  400c86:	68 11 00 00 00       	pushq  $0x11
  400c8b:	e9 d0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400c90 <__isoc99_sscanf@plt>:
  400c90:	ff 25 12 34 20 00    	jmpq   *0x203412(%rip)        # 6040a8 <__isoc99_sscanf@GLIBC_2.7>
  400c96:	68 12 00 00 00       	pushq  $0x12
  400c9b:	e9 c0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400ca0 <__printf_chk@plt>:
  400ca0:	ff 25 0a 34 20 00    	jmpq   *0x20340a(%rip)        # 6040b0 <__printf_chk@GLIBC_2.3.4>
  400ca6:	68 13 00 00 00       	pushq  $0x13
  400cab:	e9 b0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cb0 <fopen@plt>:
  400cb0:	ff 25 02 34 20 00    	jmpq   *0x203402(%rip)        # 6040b8 <fopen@GLIBC_2.2.5>
  400cb6:	68 14 00 00 00       	pushq  $0x14
  400cbb:	e9 a0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cc0 <gethostname@plt>:
  400cc0:	ff 25 fa 33 20 00    	jmpq   *0x2033fa(%rip)        # 6040c0 <gethostname@GLIBC_2.2.5>
  400cc6:	68 15 00 00 00       	pushq  $0x15
  400ccb:	e9 90 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cd0 <exit@plt>:
  400cd0:	ff 25 f2 33 20 00    	jmpq   *0x2033f2(%rip)        # 6040c8 <exit@GLIBC_2.2.5>
  400cd6:	68 16 00 00 00       	pushq  $0x16
  400cdb:	e9 80 fe ff ff       	jmpq   400b60 <.plt>

0000000000400ce0 <connect@plt>:
  400ce0:	ff 25 ea 33 20 00    	jmpq   *0x2033ea(%rip)        # 6040d0 <connect@GLIBC_2.2.5>
  400ce6:	68 17 00 00 00       	pushq  $0x17
  400ceb:	e9 70 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cf0 <__fprintf_chk@plt>:
  400cf0:	ff 25 e2 33 20 00    	jmpq   *0x2033e2(%rip)        # 6040d8 <__fprintf_chk@GLIBC_2.3.4>
  400cf6:	68 18 00 00 00       	pushq  $0x18
  400cfb:	e9 60 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d00 <sleep@plt>:
  400d00:	ff 25 da 33 20 00    	jmpq   *0x2033da(%rip)        # 6040e0 <sleep@GLIBC_2.2.5>
  400d06:	68 19 00 00 00       	pushq  $0x19
  400d0b:	e9 50 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d10 <__ctype_b_loc@plt>:
  400d10:	ff 25 d2 33 20 00    	jmpq   *0x2033d2(%rip)        # 6040e8 <__ctype_b_loc@GLIBC_2.3>
  400d16:	68 1a 00 00 00       	pushq  $0x1a
  400d1b:	e9 40 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d20 <__sprintf_chk@plt>:
  400d20:	ff 25 ca 33 20 00    	jmpq   *0x2033ca(%rip)        # 6040f0 <__sprintf_chk@GLIBC_2.3.4>
  400d26:	68 1b 00 00 00       	pushq  $0x1b
  400d2b:	e9 30 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d30 <socket@plt>:
  400d30:	ff 25 c2 33 20 00    	jmpq   *0x2033c2(%rip)        # 6040f8 <socket@GLIBC_2.2.5>
  400d36:	68 1c 00 00 00       	pushq  $0x1c
  400d3b:	e9 20 fe ff ff       	jmpq   400b60 <.plt>

Disassembly of section .plt.got:

0000000000400d40 <__gmon_start__@plt>:
  400d40:	ff 25 b2 32 20 00    	jmpq   *0x2032b2(%rip)        # 603ff8 <__gmon_start__>
  400d46:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000400d50 <_start>:
  400d50:	31 ed                	xor    %ebp,%ebp
  400d52:	49 89 d1             	mov    %rdx,%r9
  400d55:	5e                   	pop    %rsi
  400d56:	48 89 e2             	mov    %rsp,%rdx
  400d59:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400d5d:	50                   	push   %rax
  400d5e:	54                   	push   %rsp
  400d5f:	49 c7 c0 c0 26 40 00 	mov    $0x4026c0,%r8
  400d66:	48 c7 c1 50 26 40 00 	mov    $0x402650,%rcx
  400d6d:	48 c7 c7 46 0e 40 00 	mov    $0x400e46,%rdi
  400d74:	e8 97 fe ff ff       	callq  400c10 <__libc_start_main@plt>
  400d79:	f4                   	hlt    
  400d7a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400d80 <deregister_tm_clones>:
  400d80:	b8 87 4b 60 00       	mov    $0x604b87,%eax
  400d85:	55                   	push   %rbp
  400d86:	48 2d 80 4b 60 00    	sub    $0x604b80,%rax
  400d8c:	48 83 f8 0e          	cmp    $0xe,%rax
  400d90:	48 89 e5             	mov    %rsp,%rbp
  400d93:	76 1b                	jbe    400db0 <deregister_tm_clones+0x30>
  400d95:	b8 00 00 00 00       	mov    $0x0,%eax
  400d9a:	48 85 c0             	test   %rax,%rax
  400d9d:	74 11                	je     400db0 <deregister_tm_clones+0x30>
  400d9f:	5d                   	pop    %rbp
  400da0:	bf 80 4b 60 00       	mov    $0x604b80,%edi
  400da5:	ff e0                	jmpq   *%rax
  400da7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  400dae:	00 00 
  400db0:	5d                   	pop    %rbp
  400db1:	c3                   	retq   
  400db2:	0f 1f 40 00          	nopl   0x0(%rax)
  400db6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400dbd:	00 00 00 

0000000000400dc0 <register_tm_clones>:
  400dc0:	be 80 4b 60 00       	mov    $0x604b80,%esi
  400dc5:	55                   	push   %rbp
  400dc6:	48 81 ee 80 4b 60 00 	sub    $0x604b80,%rsi
  400dcd:	48 c1 fe 03          	sar    $0x3,%rsi
  400dd1:	48 89 e5             	mov    %rsp,%rbp
  400dd4:	48 89 f0             	mov    %rsi,%rax
  400dd7:	48 c1 e8 3f          	shr    $0x3f,%rax
  400ddb:	48 01 c6             	add    %rax,%rsi
  400dde:	48 d1 fe             	sar    %rsi
  400de1:	74 15                	je     400df8 <register_tm_clones+0x38>
  400de3:	b8 00 00 00 00       	mov    $0x0,%eax
  400de8:	48 85 c0             	test   %rax,%rax
  400deb:	74 0b                	je     400df8 <register_tm_clones+0x38>
  400ded:	5d                   	pop    %rbp
  400dee:	bf 80 4b 60 00       	mov    $0x604b80,%edi
  400df3:	ff e0                	jmpq   *%rax
  400df5:	0f 1f 00             	nopl   (%rax)
  400df8:	5d                   	pop    %rbp
  400df9:	c3                   	retq   
  400dfa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400e00 <__do_global_dtors_aux>:
  400e00:	80 3d a1 3d 20 00 00 	cmpb   $0x0,0x203da1(%rip)        # 604ba8 <completed.7593>
  400e07:	75 11                	jne    400e1a <__do_global_dtors_aux+0x1a>
  400e09:	55                   	push   %rbp
  400e0a:	48 89 e5             	mov    %rsp,%rbp
  400e0d:	e8 6e ff ff ff       	callq  400d80 <deregister_tm_clones>
  400e12:	5d                   	pop    %rbp
  400e13:	c6 05 8e 3d 20 00 01 	movb   $0x1,0x203d8e(%rip)        # 604ba8 <completed.7593>
  400e1a:	f3 c3                	repz retq 
  400e1c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400e20 <frame_dummy>:
  400e20:	bf 20 3e 60 00       	mov    $0x603e20,%edi
  400e25:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400e29:	75 05                	jne    400e30 <frame_dummy+0x10>
  400e2b:	eb 93                	jmp    400dc0 <register_tm_clones>
  400e2d:	0f 1f 00             	nopl   (%rax)
  400e30:	b8 00 00 00 00       	mov    $0x0,%eax
  400e35:	48 85 c0             	test   %rax,%rax
  400e38:	74 f1                	je     400e2b <frame_dummy+0xb>
  400e3a:	55                   	push   %rbp
  400e3b:	48 89 e5             	mov    %rsp,%rbp
  400e3e:	ff d0                	callq  *%rax
  400e40:	5d                   	pop    %rbp
  400e41:	e9 7a ff ff ff       	jmpq   400dc0 <register_tm_clones>

0000000000400e46 <main>:
  400e46:	53                   	push   %rbx
  400e47:	83 ff 01             	cmp    $0x1,%edi
  400e4a:	0f 84 3c 01 00 00    	je     400f8c <main+0x146>
  400e50:	48 89 f3             	mov    %rsi,%rbx
  400e53:	83 ff 02             	cmp    $0x2,%edi
  400e56:	0f 85 63 01 00 00    	jne    400fbf <main+0x179>
  400e5c:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
  400e60:	be e4 26 40 00       	mov    $0x4026e4,%esi
  400e65:	e8 46 fe ff ff       	callq  400cb0 <fopen@plt>
  400e6a:	48 89 05 3f 3d 20 00 	mov    %rax,0x203d3f(%rip)        # 604bb0 <infile>
  400e71:	48 85 c0             	test   %rax,%rax
  400e74:	0f 84 25 01 00 00    	je     400f9f <main+0x159>
  400e7a:	e8 ed 07 00 00       	callq  40166c <initialize_bomb>
  400e7f:	bf 78 27 40 00       	mov    $0x402778,%edi
  400e84:	e8 27 fd ff ff       	callq  400bb0 <puts@plt>
  400e89:	bf b8 27 40 00       	mov    $0x4027b8,%edi
  400e8e:	e8 1d fd ff ff       	callq  400bb0 <puts@plt>
  400e93:	e8 ba 0a 00 00       	callq  401952 <read_line>
  400e98:	48 89 c7             	mov    %rax,%rdi
  400e9b:	e8 40 01 00 00       	callq  400fe0 <phase_1>
  400ea0:	e8 db 0b 00 00       	callq  401a80 <phase_defused>
  400ea5:	bf e8 27 40 00       	mov    $0x4027e8,%edi
  400eaa:	e8 01 fd ff ff       	callq  400bb0 <puts@plt>
  400eaf:	e8 9e 0a 00 00       	callq  401952 <read_line>
  400eb4:	48 89 c7             	mov    %rax,%rdi
  400eb7:	e8 82 01 00 00       	callq  40103e <phase_2>
  400ebc:	e8 bf 0b 00 00       	callq  401a80 <phase_defused>
  400ec1:	bf 1d 27 40 00       	mov    $0x40271d,%edi
  400ec6:	e8 e5 fc ff ff       	callq  400bb0 <puts@plt>
  400ecb:	e8 82 0a 00 00       	callq  401952 <read_line>
  400ed0:	48 89 c7             	mov    %rax,%rdi
  400ed3:	e8 84 01 00 00       	callq  40105c <phase_3>
  400ed8:	e8 a3 0b 00 00       	callq  401a80 <phase_defused>
  400edd:	bf 3b 27 40 00       	mov    $0x40273b,%edi
  400ee2:	e8 c9 fc ff ff       	callq  400bb0 <puts@plt>
  400ee7:	e8 66 0a 00 00       	callq  401952 <read_line>
  400eec:	48 89 c7             	mov    %rax,%rdi
  400eef:	e8 ed 01 00 00       	callq  4010e1 <phase_4>
  400ef4:	e8 87 0b 00 00       	callq  401a80 <phase_defused>
  400ef9:	bf 18 28 40 00       	mov    $0x402818,%edi
  400efe:	e8 ad fc ff ff       	callq  400bb0 <puts@plt>
  400f03:	e8 4a 0a 00 00       	callq  401952 <read_line>
  400f08:	48 89 c7             	mov    %rax,%rdi
  400f0b:	e8 3a 02 00 00       	callq  40114a <phase_5>
  400f10:	e8 6b 0b 00 00       	callq  401a80 <phase_defused>
  400f15:	bf 4c 27 40 00       	mov    $0x40274c,%edi
  400f1a:	e8 91 fc ff ff       	callq  400bb0 <puts@plt>
  400f1f:	e8 2e 0a 00 00       	callq  401952 <read_line>
  400f24:	48 89 c7             	mov    %rax,%rdi
  400f27:	e8 60 03 00 00       	callq  40128c <phase_6>
  400f2c:	e8 4f 0b 00 00       	callq  401a80 <phase_defused>
  400f31:	bf 40 28 40 00       	mov    $0x402840,%edi
  400f36:	e8 75 fc ff ff       	callq  400bb0 <puts@plt>
  400f3b:	e8 12 0a 00 00       	callq  401952 <read_line>
  400f40:	48 89 c7             	mov    %rax,%rdi
  400f43:	e8 f8 03 00 00       	callq  401340 <phase_7>
  400f48:	e8 33 0b 00 00       	callq  401a80 <phase_defused>
  400f4d:	bf 60 28 40 00       	mov    $0x402860,%edi
  400f52:	e8 59 fc ff ff       	callq  400bb0 <puts@plt>
  400f57:	e8 f6 09 00 00       	callq  401952 <read_line>
  400f5c:	48 89 c7             	mov    %rax,%rdi
  400f5f:	e8 18 04 00 00       	callq  40137c <phase_8>
  400f64:	e8 17 0b 00 00       	callq  401a80 <phase_defused>
  400f69:	bf 6a 27 40 00       	mov    $0x40276a,%edi
  400f6e:	e8 3d fc ff ff       	callq  400bb0 <puts@plt>
  400f73:	e8 da 09 00 00       	callq  401952 <read_line>
  400f78:	48 89 c7             	mov    %rax,%rdi
  400f7b:	e8 8a 04 00 00       	callq  40140a <phase_9>
  400f80:	e8 fb 0a 00 00       	callq  401a80 <phase_defused>
  400f85:	b8 00 00 00 00       	mov    $0x0,%eax
  400f8a:	5b                   	pop    %rbx
  400f8b:	c3                   	retq   
  400f8c:	48 8b 05 fd 3b 20 00 	mov    0x203bfd(%rip),%rax        # 604b90 <stdin@@GLIBC_2.2.5>
  400f93:	48 89 05 16 3c 20 00 	mov    %rax,0x203c16(%rip)        # 604bb0 <infile>
  400f9a:	e9 db fe ff ff       	jmpq   400e7a <main+0x34>
  400f9f:	48 8b 4b 08          	mov    0x8(%rbx),%rcx
  400fa3:	48 8b 13             	mov    (%rbx),%rdx
  400fa6:	be e6 26 40 00       	mov    $0x4026e6,%esi
  400fab:	bf 01 00 00 00       	mov    $0x1,%edi
  400fb0:	e8 eb fc ff ff       	callq  400ca0 <__printf_chk@plt>
  400fb5:	bf 08 00 00 00       	mov    $0x8,%edi
  400fba:	e8 11 fd ff ff       	callq  400cd0 <exit@plt>
  400fbf:	48 8b 16             	mov    (%rsi),%rdx
  400fc2:	be 03 27 40 00       	mov    $0x402703,%esi
  400fc7:	bf 01 00 00 00       	mov    $0x1,%edi
  400fcc:	b8 00 00 00 00       	mov    $0x0,%eax
  400fd1:	e8 ca fc ff ff       	callq  400ca0 <__printf_chk@plt>
  400fd6:	bf 08 00 00 00       	mov    $0x8,%edi
  400fdb:	e8 f0 fc ff ff       	callq  400cd0 <exit@plt>

0000000000400fe0 <phase_1>:
  400fe0:	48 83 ec 18          	sub    $0x18,%rsp
  400fe4:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  400feb:	00 00 
  400fed:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  400ff2:	31 c0                	xor    %eax,%eax
  400ff4:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%rsp)
  400ffb:	00 
  400ffc:	48 8d 54 24 04       	lea    0x4(%rsp),%rdx
  401001:	be 85 28 40 00       	mov    $0x402885,%esi
  401006:	e8 85 fc ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  40100b:	83 f8 01             	cmp    $0x1,%eax
  40100e:	74 05                	je     401015 <phase_1+0x35>
  401010:	e8 c8 08 00 00       	callq  4018dd <explode_bomb>
  401015:	81 7c 24 04 0a 03 00 	cmpl   $0x30a,0x4(%rsp)
  40101c:	00 
  40101d:	74 05                	je     401024 <phase_1+0x44>
  40101f:	e8 b9 08 00 00       	callq  4018dd <explode_bomb>
  401024:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  401029:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401030:	00 00 
  401032:	75 05                	jne    401039 <phase_1+0x59>
  401034:	48 83 c4 18          	add    $0x18,%rsp
  401038:	c3                   	retq   
  401039:	e8 92 fb ff ff       	callq  400bd0 <__stack_chk_fail@plt>

000000000040103e <phase_2>:
  40103e:	48 83 ec 08          	sub    $0x8,%rsp
  401042:	be 88 28 40 00       	mov    $0x402888,%esi
  401047:	e8 b9 05 00 00       	callq  401605 <strings_not_equal>
  40104c:	85 c0                	test   %eax,%eax
  40104e:	75 05                	jne    401055 <phase_2+0x17>
  401050:	48 83 c4 08          	add    $0x8,%rsp
  401054:	c3                   	retq   
  401055:	e8 83 08 00 00       	callq  4018dd <explode_bomb>
  40105a:	eb f4                	jmp    401050 <phase_2+0x12>

000000000040105c <phase_3>:
  40105c:	53                   	push   %rbx
  40105d:	48 89 fb             	mov    %rdi,%rbx
  401060:	bf b0 28 40 00       	mov    $0x4028b0,%edi
  401065:	e8 7d 05 00 00       	callq  4015e7 <string_length>
  40106a:	8d 78 01             	lea    0x1(%rax),%edi
  40106d:	48 63 ff             	movslq %edi,%rdi
  401070:	e8 fb fb ff ff       	callq  400c70 <malloc@plt>
  401075:	48 ba 54 68 65 20 71 	movabs $0x6369757120656854,%rdx
  40107c:	75 69 63 
  40107f:	48 89 10             	mov    %rdx,(%rax)
  401082:	48 b9 6b 20 62 72 6f 	movabs $0x206e776f7262206b,%rcx
  401089:	77 6e 20 
  40108c:	48 89 48 08          	mov    %rcx,0x8(%rax)
  401090:	48 be 66 6f 78 20 6a 	movabs $0x706d756a20786f66,%rsi
  401097:	75 6d 70 
  40109a:	48 89 70 10          	mov    %rsi,0x10(%rax)
  40109e:	48 ba 73 20 6f 76 65 	movabs $0x74207265766f2073,%rdx
  4010a5:	72 20 74 
  4010a8:	48 89 50 18          	mov    %rdx,0x18(%rax)
  4010ac:	48 b9 68 65 20 6c 61 	movabs $0x20797a616c206568,%rcx
  4010b3:	7a 79 20 
  4010b6:	48 89 48 20          	mov    %rcx,0x20(%rax)
  4010ba:	c7 40 28 64 6f 67 2e 	movl   $0x2e676f64,0x28(%rax)
  4010c1:	c6 40 2c 00          	movb   $0x0,0x2c(%rax)
  4010c5:	c6 40 08 36          	movb   $0x36,0x8(%rax)
  4010c9:	48 89 c6             	mov    %rax,%rsi
  4010cc:	48 89 df             	mov    %rbx,%rdi
  4010cf:	e8 31 05 00 00       	callq  401605 <strings_not_equal>
  4010d4:	85 c0                	test   %eax,%eax
  4010d6:	75 02                	jne    4010da <phase_3+0x7e>
  4010d8:	5b                   	pop    %rbx
  4010d9:	c3                   	retq   
  4010da:	e8 fe 07 00 00       	callq  4018dd <explode_bomb>
  4010df:	eb f7                	jmp    4010d8 <phase_3+0x7c>

00000000004010e1 <phase_4>:
  4010e1:	55                   	push   %rbp
  4010e2:	53                   	push   %rbx
  4010e3:	48 83 ec 28          	sub    $0x28,%rsp
  4010e7:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4010ee:	00 00 
  4010f0:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  4010f5:	31 c0                	xor    %eax,%eax
  4010f7:	48 89 e6             	mov    %rsp,%rsi
  4010fa:	e8 14 08 00 00       	callq  401913 <read_six_numbers>
  4010ff:	83 3c 24 04          	cmpl   $0x4,(%rsp)
  401103:	74 05                	je     40110a <phase_4+0x29>      //40110a
  401105:	e8 d3 07 00 00       	callq  4018dd <explode_bomb>
  40110a:	48 89 e3             	mov    %rsp,%rbx
  40110d:	48 8d 6c 24 14       	lea    0x14(%rsp),%rbp
  401112:	eb 09                	jmp    40111d <phase_4+0x3c>      //40111d
  401114:	48 83 c3 04          	add    $0x4,%rbx
  401118:	48 39 eb             	cmp    %rbp,%rbx
  40111b:	74 11                	je     40112e <phase_4+0x4d>      //40112e
  40111d:	8b 03                	mov    (%rbx),%eax
  40111f:	8d 04 40             	lea    (%rax,%rax,2),%eax
  401122:	39 43 04             	cmp    %eax,0x4(%rbx)
  401125:	74 ed                	je     401114 <phase_4+0x33>      //401114
  401127:	e8 b1 07 00 00       	callq  4018dd <explode_bomb>
  40112c:	eb e6                	jmp    401114 <phase_4+0x33>      //401114
  40112e:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
  401133:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  40113a:	00 00 
  40113c:	75 07                	jne    401145 <phase_4+0x64>      //401145
  40113e:	48 83 c4 28          	add    $0x28,%rsp
  401142:	5b                   	pop    %rbx
  401143:	5d                   	pop    %rbp
  401144:	c3                   	retq   
  401145:	e8 86 fa ff ff       	callq  400bd0 <__stack_chk_fail@plt>

000000000040114a <phase_5>:
  40114a:	41 55                	push   %r13
  40114c:	41 54                	push   %r12
  40114e:	55                   	push   %rbp
  40114f:	53                   	push   %rbx
  401150:	48 83 ec 68          	sub    $0x68,%rsp
  401154:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40115b:	00 00 
  40115d:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
  401162:	31 c0                	xor    %eax,%eax
  401164:	48 89 e6             	mov    %rsp,%rsi
  401167:	e8 a7 07 00 00       	callq  401913 <read_six_numbers>
  40116c:	49 89 e4             	mov    %rsp,%r12
  40116f:	41 bd 00 00 00 00    	mov    $0x0,%r13d
  401175:	eb 24                	jmp    40119b <phase_5+0x51> (j1)
  401177:	41 83 c5 01          	add    $0x1,%r13d                       //j4
  40117b:	41 83 fd 06          	cmp    $0x6,%r13d
  40117f:	74 37                	je     4011b8 <phase_5+0x6e> (j2)
  401181:	44 89 eb             	mov    %r13d,%ebx
  401184:	48 63 c3             	movslq %ebx,%rax                        //j3
  401187:	8b 04 84             	mov    (%rsp,%rax,4),%eax
  40118a:	39 45 00             	cmp    %eax,0x0(%rbp)
  40118d:	74 22                	je     4011b1 <phase_5+0x67> (e)
  40118f:	83 c3 01             	add    $0x1,%ebx
  401192:	83 fb 05             	cmp    $0x5,%ebx
  401195:	7e ed                	jle    401184 <phase_5+0x3a> (j3)
  401197:	49 83 c4 04          	add    $0x4,%r12
  40119b:	4c 89 e5             	mov    %r12,%rbp                        //j1
  40119e:	41 8b 04 24          	mov    (%r12),%eax
  4011a2:	83 e8 01             	sub    $0x1,%eax
  4011a5:	83 f8 05             	cmp    $0x5,%eax
  4011a8:	76 cd                	jbe    401177 <phase_5+0x2d> (j4)
  4011aa:	e8 2e 07 00 00       	callq  4018dd <explode_bomb>
  4011af:	eb c6                	jmp    401177 <phase_5+0x2d> (j4)
  4011b1:	e8 27 07 00 00       	callq  4018dd <explode_bomb>            //e
  4011b6:	eb d7                	jmp    40118f <phase_5+0x45>
  4011b8:	be 00 00 00 00       	mov    $0x0,%esi                        //j2
  4011bd:	8b 0c 34             	mov    (%rsp,%rsi,1),%ecx               //j7
  4011c0:	b8 01 00 00 00       	mov    $0x1,%eax
  4011c5:	ba 00 43 60 00       	mov    $0x604300,%edx
  4011ca:	83 f9 01             	cmp    $0x1,%ecx
  4011cd:	7e 0b                	jle    4011da <phase_5+0x90> (j5)
  4011cf:	48 8b 52 08          	mov    0x8(%rdx),%rdx                   //j6
  4011d3:	83 c0 01             	add    $0x1,%eax
  4011d6:	39 c8                	cmp    %ecx,%eax
  4011d8:	75 f5                	jne    4011cf <phase_5+0x85> (j6)
  4011da:	48 89 54 74 20       	mov    %rdx,0x20(%rsp,%rsi,2)           //j5
  4011df:	48 83 c6 04          	add    $0x4,%rsi
  4011e3:	48 83 fe 18          	cmp    $0x18,%rsi
  4011e7:	75 d4                	jne    4011bd <phase_5+0x73> (j7)
  4011e9:	48 8b 5c 24 20       	mov    0x20(%rsp),%rbx
  4011ee:	48 8d 44 24 20       	lea    0x20(%rsp),%rax
  4011f3:	48 8d 74 24 48       	lea    0x48(%rsp),%rsi
  4011f8:	48 89 d9             	mov    %rbx,%rcx
  4011fb:	48 8b 50 08          	mov    0x8(%rax),%rdx                   //j8
  4011ff:	48 89 51 08          	mov    %rdx,0x8(%rcx) ????????
  401203:	48 83 c0 08          	add    $0x8,%rax
  401207:	48 89 d1             	mov    %rdx,%rcx
  40120a:	48 39 c6             	cmp    %rax,%rsi
  40120d:	75 ec                	jne    4011fb <phase_5+0xb1> (j8)
  40120f:	48 c7 42 08 00 00 00 	movq   $0x0,0x8(%rdx)
  401216:	00 
  401217:	bd 05 00 00 00       	mov    $0x5,%ebp
  40121c:	eb 09                	jmp    401227 <phase_5+0xdd> (j9)
  40121e:	48 8b 5b 08          	mov    0x8(%rbx),%rbx                   //j11
  401222:	83 ed 01             	sub    $0x1,%ebp
  401225:	74 11                	je     401238 <phase_5+0xee> (j10)
  401227:	48 8b 43 08          	mov    0x8(%rbx),%rax                   //j9
  40122b:	8b 00                	mov    (%rax),%eax
  40122d:	39 03                	cmp    %eax,(%rbx)
  40122f:	7e ed                	jle    40121e <phase_5+0xd4> (j11)
  401231:	e8 a7 06 00 00       	callq  4018dd <explode_bomb>
  401236:	eb e6                	jmp    40121e <phase_5+0xd4> (j11)
  401238:	48 8b 44 24 58       	mov    0x58(%rsp),%rax                  //j10
  40123d:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401244:	00 00 
  401246:	75 0b                	jne    401253 <phase_5+0x109> (j12)
  401248:	48 83 c4 68          	add    $0x68,%rsp
  40124c:	5b                   	pop    %rbx
  40124d:	5d                   	pop    %rbp
  40124e:	41 5c                	pop    %r12
  401250:	41 5d                	pop    %r13
  401252:	c3                   	retq   
  401253:	e8 78 f9 ff ff       	callq  400bd0 <__stack_chk_fail@plt>    //j12

0000000000401258 <fun6>:
  401258:	53                   	push   %rbx
  401259:	89 d0                	mov    %edx,%eax
  40125b:	29 f0                	sub    %esi,%eax
  40125d:	89 c3                	mov    %eax,%ebx
  40125f:	c1 eb 1f             	shr    $0x1f,%ebx
  401262:	01 c3                	add    %eax,%ebx
  401264:	d1 fb                	sar    %ebx
  401266:	01 f3                	add    %esi,%ebx
  401268:	39 fb                	cmp    %edi,%ebx
  40126a:	7f 08                	jg     401274 <fun6+0x1c>
  40126c:	39 fb                	cmp    %edi,%ebx
  40126e:	7c 10                	jl     401280 <fun6+0x28>
  401270:	89 d8                	mov    %ebx,%eax
  401272:	5b                   	pop    %rbx
  401273:	c3                   	retq   
  401274:	8d 53 ff             	lea    -0x1(%rbx),%edx
  401277:	e8 dc ff ff ff       	callq  401258 <fun6>
  40127c:	01 c3                	add    %eax,%ebx
  40127e:	eb f0                	jmp    401270 <fun6+0x18>
  401280:	8d 73 01             	lea    0x1(%rbx),%esi
  401283:	e8 d0 ff ff ff       	callq  401258 <fun6>
  401288:	01 c3                	add    %eax,%ebx
  40128a:	eb e4                	jmp    401270 <fun6+0x18>

000000000040128c <phase_6>:
  40128c:	48 83 ec 18          	sub    $0x18,%rsp
  401290:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401297:	00 00 
  401299:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  40129e:	31 c0                	xor    %eax,%eax
  4012a0:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx
  4012a5:	48 89 e2             	mov    %rsp,%rdx
  4012a8:	be 4d 2b 40 00       	mov    $0x402b4d,%esi
  4012ad:	e8 de f9 ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  4012b2:	83 f8 02             	cmp    $0x2,%eax
  4012b5:	74 36                	je     4012ed <phase_6+0x61>
  4012b7:	e8 21 06 00 00       	callq  4018dd <explode_bomb>
  4012bc:	ba 0e 00 00 00       	mov    $0xe,%edx
  4012c1:	be 00 00 00 00       	mov    $0x0,%esi
  4012c6:	8b 3c 24             	mov    (%rsp),%edi
  4012c9:	e8 8a ff ff ff       	callq  401258 <fun6>
  4012ce:	83 f8 2b             	cmp    $0x2b,%eax
  4012d1:	74 22                	je     4012f5 <phase_6+0x69>
  4012d3:	e8 05 06 00 00       	callq  4018dd <explode_bomb>
  4012d8:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  4012dd:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  4012e4:	00 00 
  4012e6:	75 16                	jne    4012fe <phase_6+0x72>
  4012e8:	48 83 c4 18          	add    $0x18,%rsp
  4012ec:	c3                   	retq   
  4012ed:	83 3c 24 0e          	cmpl   $0xe,(%rsp)
  4012f1:	76 c9                	jbe    4012bc <phase_6+0x30>
  4012f3:	eb c2                	jmp    4012b7 <phase_6+0x2b>
  4012f5:	83 7c 24 04 2b       	cmpl   $0x2b,0x4(%rsp)
  4012fa:	75 d7                	jne    4012d3 <phase_6+0x47>
  4012fc:	eb da                	jmp    4012d8 <phase_6+0x4c>
  4012fe:	e8 cd f8 ff ff       	callq  400bd0 <__stack_chk_fail@plt>

0000000000401303 <fun7>:
  401303:	48 85 ff             	test   %rdi,%rdi
  401306:	74 32                	je     40133a <fun7+0x37>
  401308:	48 83 ec 08          	sub    $0x8,%rsp              //subtract 8 from the stack pointer
  40130c:	8b 17                	mov    (%rdi),%edx            //move the value stored at address of 0x604120 to edx
  40130e:	39 f2                	cmp    %esi,%edx              //compare esi (input) to edx (1bb) (443)
  401310:	7f 1b                	jg     40132d <fun7+0x2a>     //if edx > esi jump to 0x40132d
  401312:	b8 00 00 00 00       	mov    $0x0,%eax              //set eax to 0
  401317:	39 f2                	cmp    %esi,%edx              //compare esi (input) to edx (1bb) (443)
  401319:	74 0d                	je     401328 <fun7+0x25>     //if edx == esi jump to 0x401328 (add 8 to %rsp and return)
  40131b:	48 8b 7f 10          	mov    0x10(%rdi),%rdi        //set rdi to memory address of next node (change rdi by 10)
  40131f:	e8 df ff ff ff       	callq  401303 <fun7>          //recursive call
  401324:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax  //set eax to 2*rax + 1.
  401328:	48 83 c4 08          	add    $0x8,%rsp              //add 8 to rsp
  40132c:	c3                   	retq                          //return
  40132d:	48 8b 7f 08          	mov    0x8(%rdi),%rdi         //set rdi to node pointer
  401331:	e8 cd ff ff ff       	callq  401303 <fun7>          //recursive call
  401336:	01 c0                	add    %eax,%eax              //double return value
  401338:	eb ee                	jmp    401328 <fun7+0x25>     //if edx == esi jump to 0x401328 (add 8 to %rsp and return)
  40133a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40133f:	c3                   	retq   

0000000000401340 <phase_7>:
  401340:	53                   	push   %rbx
  401341:	ba 0a 00 00 00       	mov    $0xa,%edx
  401346:	be 00 00 00 00       	mov    $0x0,%esi
  40134b:	e8 10 f9 ff ff       	callq  400c60 <strtol@plt>
  401350:	48 89 c3             	mov    %rax,%rbx
  401353:	8d 40 ff             	lea    -0x1(%rax),%eax
  401356:	3d ec 03 00 00       	cmp    $0x3ec,%eax              //input is less than 1005
  40135b:	77 18                	ja     401375 <phase_7+0x35>
  40135d:	89 de                	mov    %ebx,%esi                //move input to esi
  40135f:	bf 20 41 60 00       	mov    $0x604120,%edi           //move 6308128 to edi
  401364:	e8 9a ff ff ff       	callq  401303 <fun7>
  401369:	83 f8 06             	cmp    $0x6,%eax                //answer has to be 6
  40136c:	74 05                	je     401373 <phase_7+0x33>
  40136e:	e8 6a 05 00 00       	callq  4018dd <explode_bomb>
  401373:	5b                   	pop    %rbx
  401374:	c3                   	retq   
  401375:	e8 63 05 00 00       	callq  4018dd <explode_bomb>
  40137a:	eb e1                	jmp    40135d <phase_7+0x1d>

000000000040137c <phase_8>:
  40137c:	48 83 ec 18          	sub    $0x18,%rsp
  401380:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401387:	00 00 
  401389:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  40138e:	31 c0                	xor    %eax,%eax
  401390:	48 8d 4c 24 04       	lea    0x4(%rsp),%rcx
  401395:	48 89 e2             	mov    %rsp,%rdx
  401398:	be 4d 2b 40 00       	mov    $0x402b4d,%esi
  40139d:	e8 ee f8 ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  4013a2:	83 f8 01             	cmp    $0x1,%eax                //there has to be more than 1 input
  4013a5:	7e 57                	jle    4013fe <phase_8+0x82>    //or else explode bomb
  4013a7:	8b 04 24             	mov    (%rsp),%eax              //move the stack pointer to rax
  4013aa:	83 e0 0f             	and    $0xf,%eax                //get the last 
  4013ad:	89 04 24             	mov    %eax,(%rsp)              //move eax to the top of the stack
  4013b0:	83 f8 0f             	cmp    $0xf,%eax
  4013b3:	74 2f                	je     4013e4 <phase_8+0x68>
  4013b5:	b9 00 00 00 00       	mov    $0x0,%ecx                //set ecx to 0
  4013ba:	ba 00 00 00 00       	mov    $0x0,%edx                //set edx to 0
  4013bf:	83 c2 01             	add    $0x1,%edx                //add 1 to edx      //start of loop
  4013c2:	48 98                	cltq   
  4013c4:	8b 04 85 20 29 40 00 	mov    0x402920(,%rax,4),%eax   //eax = a[eax]
  4013cb:	01 c1                	add    %eax,%ecx                //ecx = ecx + eax
  4013cd:	83 f8 0f             	cmp    $0xf,%eax                //compare eax to 15
  4013d0:	75 ed                	jne    4013bf <phase_8+0x43>    //if eax != 15 then go to the start of the loop
  4013d2:	c7 04 24 0f 00 00 00 	movl   $0xf,(%rsp)              //move 15 to the top of the stack
  4013d9:	83 fa 04             	cmp    $0x4,%edx                //compare edx to 4
  4013dc:	75 06                	jne    4013e4 <phase_8+0x68>    //if edx != 4 then explode the bomb
  4013de:	3b 4c 24 04          	cmp    0x4(%rsp),%ecx           //compare the second item to ecx (second argument I believe)
  4013e2:	74 05                	je     4013e9 <phase_8+0x6d>    //if they are unequal explode the bomb, if they are equal return.
  4013e4:	e8 f4 04 00 00       	callq  4018dd <explode_bomb>
  4013e9:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  4013ee:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  4013f5:	00 00 
  4013f7:	75 0c                	jne    401405 <phase_8+0x89>
  4013f9:	48 83 c4 18          	add    $0x18,%rsp
  4013fd:	c3                   	retq   
  4013fe:	e8 da 04 00 00       	callq  4018dd <explode_bomb>
  401403:	eb a2                	jmp    4013a7 <phase_8+0x2b>
  401405:	e8 c6 f7 ff ff       	callq  400bd0 <__stack_chk_fail@plt>

000000000040140a <phase_9>:
  40140a:	48 83 ec 28          	sub    $0x28,%rsp
  40140e:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401415:	00 00 
  401417:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  40141c:	31 c0                	xor    %eax,%eax
  40141e:	4c 8d 44 24 14       	lea    0x14(%rsp),%r8
  401423:	48 8d 4c 24 0f       	lea    0xf(%rsp),%rcx
  401428:	48 8d 54 24 10       	lea    0x10(%rsp),%rdx
  40142d:	be 7f 28 40 00       	mov    $0x40287f,%esi
  401432:	e8 59 f8 ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  401437:	83 f8 02             	cmp    $0x2,%eax                //make sure there is at least 2 arguments
  40143a:	7e 16                	jle    401452 <phase_9+0x48>    //if there is less, explode bomb
  40143c:	83 7c 24 10 07       	cmpl   $0x7,0x10(%rsp)          //make sure the first argument is less than (or equal to?) 7
  401441:	0f 87 f6 00 00 00    	ja     40153d <phase_9+0x133>   //if not, then explode bomb
  401447:	8b 44 24 10          	mov    0x10(%rsp),%eax          //move first argument to eax
  40144b:	ff 24 c5 e0 28 40 00 	jmpq   *0x4028e0(,%rax,8)       //jump to whatever arg1 is.
  401452:	e8 86 04 00 00       	callq  4018dd <explode_bomb>
  401457:	eb e3                	jmp    40143c <phase_9+0x32>
  401459:	b8 71 00 00 00       	mov    $0x71,%eax               //0
  40145e:	83 7c 24 14 70       	cmpl   $0x70,0x14(%rsp)
  401463:	0f 84 de 00 00 00    	je     401547 <phase_9+0x13d>
  401469:	e8 6f 04 00 00       	callq  4018dd <explode_bomb>
  40146e:	b8 71 00 00 00       	mov    $0x71,%eax
  401473:	e9 cf 00 00 00       	jmpq   401547 <phase_9+0x13d>
  401478:	b8 6c 00 00 00       	mov    $0x6c,%eax               //1
  40147d:	83 7c 24 14 3f       	cmpl   $0x3f,0x14(%rsp)
  401482:	0f 84 bf 00 00 00    	je     401547 <phase_9+0x13d>
  401488:	e8 50 04 00 00       	callq  4018dd <explode_bomb>
  40148d:	b8 6c 00 00 00       	mov    $0x6c,%eax
  401492:	e9 b0 00 00 00       	jmpq   401547 <phase_9+0x13d>
  401497:	b8 6c 00 00 00       	mov    $0x6c,%eax               //2
  40149c:	81 7c 24 14 bf 02 00 	cmpl   $0x2bf,0x14(%rsp)
  4014a3:	00 
  4014a4:	0f 84 9d 00 00 00    	je     401547 <phase_9+0x13d>
  4014aa:	e8 2e 04 00 00       	callq  4018dd <explode_bomb>
  4014af:	b8 6c 00 00 00       	mov    $0x6c,%eax
  4014b4:	e9 8e 00 00 00       	jmpq   401547 <phase_9+0x13d>
  4014b9:	b8 6f 00 00 00       	mov    $0x6f,%eax               //3
  4014be:	81 7c 24 14 9c 01 00 	cmpl   $0x19c,0x14(%rsp)
  4014c5:	00 
  4014c6:	74 7f                	je     401547 <phase_9+0x13d>
  4014c8:	e8 10 04 00 00       	callq  4018dd <explode_bomb>
  4014cd:	b8 6f 00 00 00       	mov    $0x6f,%eax
  4014d2:	eb 73                	jmp    401547 <phase_9+0x13d>
  4014d4:	b8 76 00 00 00       	mov    $0x76,%eax               //4
  4014d9:	83 7c 24 14 35       	cmpl   $0x35,0x14(%rsp)
  4014de:	74 67                	je     401547 <phase_9+0x13d>
  4014e0:	e8 f8 03 00 00       	callq  4018dd <explode_bomb>
  4014e5:	b8 76 00 00 00       	mov    $0x76,%eax
  4014ea:	eb 5b                	jmp    401547 <phase_9+0x13d>
  4014ec:	b8 69 00 00 00       	mov    $0x69,%eax               //5
  4014f1:	81 7c 24 14 ca 03 00 	cmpl   $0x3ca,0x14(%rsp)
  4014f8:	00 
  4014f9:	74 4c                	je     401547 <phase_9+0x13d>
  4014fb:	e8 dd 03 00 00       	callq  4018dd <explode_bomb>
  401500:	b8 69 00 00 00       	mov    $0x69,%eax
  401505:	eb 40                	jmp    401547 <phase_9+0x13d>
  401507:	b8 79 00 00 00       	mov    $0x79,%eax               //6
  40150c:	81 7c 24 14 34 02 00 	cmpl   $0x234,0x14(%rsp)
  401513:	00 
  401514:	74 31                	je     401547 <phase_9+0x13d>
  401516:	e8 c2 03 00 00       	callq  4018dd <explode_bomb>
  40151b:	b8 79 00 00 00       	mov    $0x79,%eax
  401520:	eb 25                	jmp    401547 <phase_9+0x13d>
  401522:	b8 6c 00 00 00       	mov    $0x6c,%eax               //7
  401527:	81 7c 24 14 98 02 00 	cmpl   $0x298,0x14(%rsp)
  40152e:	00 
  40152f:	74 16                	je     401547 <phase_9+0x13d>
  401531:	e8 a7 03 00 00       	callq  4018dd <explode_bomb>
  401536:	b8 6c 00 00 00       	mov    $0x6c,%eax
  40153b:	eb 0a                	jmp    401547 <phase_9+0x13d>
  40153d:	e8 9b 03 00 00       	callq  4018dd <explode_bomb>
  401542:	b8 6b 00 00 00       	mov    $0x6b,%eax
  401547:	3a 44 24 0f          	cmp    0xf(%rsp),%al
  40154b:	74 05                	je     401552 <phase_9+0x148>
  40154d:	e8 8b 03 00 00       	callq  4018dd <explode_bomb>
  401552:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
  401557:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  40155e:	00 00 
  401560:	75 05                	jne    401567 <phase_9+0x15d>
  401562:	48 83 c4 28          	add    $0x28,%rsp
  401566:	c3                   	retq   
  401567:	e8 64 f6 ff ff       	callq  400bd0 <__stack_chk_fail@plt>

000000000040156c <sig_handler>:
  40156c:	48 83 ec 08          	sub    $0x8,%rsp
  401570:	bf 60 29 40 00       	mov    $0x402960,%edi
  401575:	e8 36 f6 ff ff       	callq  400bb0 <puts@plt>
  40157a:	bf 03 00 00 00       	mov    $0x3,%edi
  40157f:	e8 7c f7 ff ff       	callq  400d00 <sleep@plt>
  401584:	be c9 2a 40 00       	mov    $0x402ac9,%esi
  401589:	bf 01 00 00 00       	mov    $0x1,%edi
  40158e:	b8 00 00 00 00       	mov    $0x0,%eax
  401593:	e8 08 f7 ff ff       	callq  400ca0 <__printf_chk@plt>
  401598:	48 8b 3d e1 35 20 00 	mov    0x2035e1(%rip),%rdi        # 604b80 <stdout@@GLIBC_2.2.5>
  40159f:	e8 dc f6 ff ff       	callq  400c80 <fflush@plt>
  4015a4:	bf 01 00 00 00       	mov    $0x1,%edi
  4015a9:	e8 52 f7 ff ff       	callq  400d00 <sleep@plt>
  4015ae:	bf d1 2a 40 00       	mov    $0x402ad1,%edi
  4015b3:	e8 f8 f5 ff ff       	callq  400bb0 <puts@plt>
  4015b8:	bf 10 00 00 00       	mov    $0x10,%edi
  4015bd:	e8 0e f7 ff ff       	callq  400cd0 <exit@plt>

00000000004015c2 <invalid_phase>:
  4015c2:	48 83 ec 08          	sub    $0x8,%rsp
  4015c6:	48 89 fa             	mov    %rdi,%rdx
  4015c9:	be d9 2a 40 00       	mov    $0x402ad9,%esi
  4015ce:	bf 01 00 00 00       	mov    $0x1,%edi
  4015d3:	b8 00 00 00 00       	mov    $0x0,%eax
  4015d8:	e8 c3 f6 ff ff       	callq  400ca0 <__printf_chk@plt>
  4015dd:	bf 08 00 00 00       	mov    $0x8,%edi
  4015e2:	e8 e9 f6 ff ff       	callq  400cd0 <exit@plt>

00000000004015e7 <string_length>:
  4015e7:	80 3f 00             	cmpb   $0x0,(%rdi)
  4015ea:	74 13                	je     4015ff <string_length+0x18>
  4015ec:	b8 00 00 00 00       	mov    $0x0,%eax
  4015f1:	48 83 c7 01          	add    $0x1,%rdi
  4015f5:	83 c0 01             	add    $0x1,%eax
  4015f8:	80 3f 00             	cmpb   $0x0,(%rdi)
  4015fb:	75 f4                	jne    4015f1 <string_length+0xa>
  4015fd:	f3 c3                	repz retq 
  4015ff:	b8 00 00 00 00       	mov    $0x0,%eax
  401604:	c3                   	retq   

0000000000401605 <strings_not_equal>:
  401605:	41 54                	push   %r12
  401607:	55                   	push   %rbp
  401608:	53                   	push   %rbx
  401609:	48 89 fb             	mov    %rdi,%rbx
  40160c:	48 89 f5             	mov    %rsi,%rbp
  40160f:	e8 d3 ff ff ff       	callq  4015e7 <string_length>
  401614:	41 89 c4             	mov    %eax,%r12d
  401617:	48 89 ef             	mov    %rbp,%rdi
  40161a:	e8 c8 ff ff ff       	callq  4015e7 <string_length>
  40161f:	ba 01 00 00 00       	mov    $0x1,%edx
  401624:	41 39 c4             	cmp    %eax,%r12d
  401627:	74 07                	je     401630 <strings_not_equal+0x2b>
  401629:	89 d0                	mov    %edx,%eax
  40162b:	5b                   	pop    %rbx
  40162c:	5d                   	pop    %rbp
  40162d:	41 5c                	pop    %r12
  40162f:	c3                   	retq   
  401630:	0f b6 03             	movzbl (%rbx),%eax
  401633:	84 c0                	test   %al,%al
  401635:	74 27                	je     40165e <strings_not_equal+0x59>
  401637:	3a 45 00             	cmp    0x0(%rbp),%al
  40163a:	75 29                	jne    401665 <strings_not_equal+0x60>
  40163c:	48 83 c3 01          	add    $0x1,%rbx
  401640:	48 83 c5 01          	add    $0x1,%rbp
  401644:	0f b6 03             	movzbl (%rbx),%eax
  401647:	84 c0                	test   %al,%al
  401649:	74 0c                	je     401657 <strings_not_equal+0x52>
  40164b:	3a 45 00             	cmp    0x0(%rbp),%al
  40164e:	74 ec                	je     40163c <strings_not_equal+0x37>
  401650:	ba 01 00 00 00       	mov    $0x1,%edx
  401655:	eb d2                	jmp    401629 <strings_not_equal+0x24>
  401657:	ba 00 00 00 00       	mov    $0x0,%edx
  40165c:	eb cb                	jmp    401629 <strings_not_equal+0x24>
  40165e:	ba 00 00 00 00       	mov    $0x0,%edx
  401663:	eb c4                	jmp    401629 <strings_not_equal+0x24>
  401665:	ba 01 00 00 00       	mov    $0x1,%edx
  40166a:	eb bd                	jmp    401629 <strings_not_equal+0x24>

000000000040166c <initialize_bomb>:
  40166c:	53                   	push   %rbx
  40166d:	48 81 ec 50 20 00 00 	sub    $0x2050,%rsp
  401674:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40167b:	00 00 
  40167d:	48 89 84 24 48 20 00 	mov    %rax,0x2048(%rsp)
  401684:	00 
  401685:	31 c0                	xor    %eax,%eax
  401687:	be 6c 15 40 00       	mov    $0x40156c,%esi
  40168c:	bf 02 00 00 00       	mov    $0x2,%edi
  401691:	e8 9a f5 ff ff       	callq  400c30 <signal@plt>
  401696:	be 40 00 00 00       	mov    $0x40,%esi
  40169b:	48 89 e7             	mov    %rsp,%rdi
  40169e:	e8 1d f6 ff ff       	callq  400cc0 <gethostname@plt>
  4016a3:	85 c0                	test   %eax,%eax
  4016a5:	75 46                	jne    4016ed <initialize_bomb+0x81>
  4016a7:	48 8b 3d d2 30 20 00 	mov    0x2030d2(%rip),%rdi        # 604780 <host_table>
  4016ae:	bb 88 47 60 00       	mov    $0x604788,%ebx
  4016b3:	48 85 ff             	test   %rdi,%rdi
  4016b6:	74 19                	je     4016d1 <initialize_bomb+0x65>
  4016b8:	48 89 e6             	mov    %rsp,%rsi
  4016bb:	e8 c0 f4 ff ff       	callq  400b80 <strcasecmp@plt>
  4016c0:	85 c0                	test   %eax,%eax
  4016c2:	74 60                	je     401724 <initialize_bomb+0xb8>
  4016c4:	48 83 c3 08          	add    $0x8,%rbx
  4016c8:	48 8b 7b f8          	mov    -0x8(%rbx),%rdi
  4016cc:	48 85 ff             	test   %rdi,%rdi
  4016cf:	75 e7                	jne    4016b8 <initialize_bomb+0x4c>
  4016d1:	bf d0 29 40 00       	mov    $0x4029d0,%edi
  4016d6:	e8 d5 f4 ff ff       	callq  400bb0 <puts@plt>
  4016db:	48 89 e7             	mov    %rsp,%rdi
  4016de:	e8 cd f4 ff ff       	callq  400bb0 <puts@plt>
  4016e3:	bf 08 00 00 00       	mov    $0x8,%edi
  4016e8:	e8 e3 f5 ff ff       	callq  400cd0 <exit@plt>
  4016ed:	bf 98 29 40 00       	mov    $0x402998,%edi
  4016f2:	e8 b9 f4 ff ff       	callq  400bb0 <puts@plt>
  4016f7:	bf 08 00 00 00       	mov    $0x8,%edi
  4016fc:	e8 cf f5 ff ff       	callq  400cd0 <exit@plt>
  401701:	48 8d 54 24 40       	lea    0x40(%rsp),%rdx
  401706:	be ea 2a 40 00       	mov    $0x402aea,%esi
  40170b:	bf 01 00 00 00       	mov    $0x1,%edi
  401710:	b8 00 00 00 00       	mov    $0x0,%eax
  401715:	e8 86 f5 ff ff       	callq  400ca0 <__printf_chk@plt>
  40171a:	bf 08 00 00 00       	mov    $0x8,%edi
  40171f:	e8 ac f5 ff ff       	callq  400cd0 <exit@plt>
  401724:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  401729:	e8 cb 0c 00 00       	callq  4023f9 <init_driver>
  40172e:	85 c0                	test   %eax,%eax
  401730:	78 cf                	js     401701 <initialize_bomb+0x95>
  401732:	48 8b 84 24 48 20 00 	mov    0x2048(%rsp),%rax
  401739:	00 
  40173a:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401741:	00 00 
  401743:	75 09                	jne    40174e <initialize_bomb+0xe2>
  401745:	48 81 c4 50 20 00 00 	add    $0x2050,%rsp
  40174c:	5b                   	pop    %rbx
  40174d:	c3                   	retq   
  40174e:	e8 7d f4 ff ff       	callq  400bd0 <__stack_chk_fail@plt>

0000000000401753 <initialize_bomb_solve>:
  401753:	f3 c3                	repz retq 

0000000000401755 <blank_line>:
  401755:	55                   	push   %rbp
  401756:	53                   	push   %rbx
  401757:	48 83 ec 08          	sub    $0x8,%rsp
  40175b:	48 89 fd             	mov    %rdi,%rbp
  40175e:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
  401762:	84 db                	test   %bl,%bl
  401764:	74 1e                	je     401784 <blank_line+0x2f>
  401766:	e8 a5 f5 ff ff       	callq  400d10 <__ctype_b_loc@plt>
  40176b:	48 83 c5 01          	add    $0x1,%rbp
  40176f:	48 0f be db          	movsbq %bl,%rbx
  401773:	48 8b 00             	mov    (%rax),%rax
  401776:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
  40177b:	75 e1                	jne    40175e <blank_line+0x9>
  40177d:	b8 00 00 00 00       	mov    $0x0,%eax
  401782:	eb 05                	jmp    401789 <blank_line+0x34>
  401784:	b8 01 00 00 00       	mov    $0x1,%eax
  401789:	48 83 c4 08          	add    $0x8,%rsp
  40178d:	5b                   	pop    %rbx
  40178e:	5d                   	pop    %rbp
  40178f:	c3                   	retq   

0000000000401790 <skip>:
  401790:	53                   	push   %rbx
  401791:	48 63 05 14 34 20 00 	movslq 0x203414(%rip),%rax        # 604bac <num_input_strings>
  401798:	48 8d 3c 80          	lea    (%rax,%rax,4),%rdi
  40179c:	48 c1 e7 04          	shl    $0x4,%rdi
  4017a0:	48 81 c7 c0 4b 60 00 	add    $0x604bc0,%rdi
  4017a7:	48 8b 15 02 34 20 00 	mov    0x203402(%rip),%rdx        # 604bb0 <infile>
  4017ae:	be 50 00 00 00       	mov    $0x50,%esi
  4017b3:	e8 68 f4 ff ff       	callq  400c20 <fgets@plt>
  4017b8:	48 89 c3             	mov    %rax,%rbx
  4017bb:	48 85 c0             	test   %rax,%rax
  4017be:	74 0c                	je     4017cc <skip+0x3c>
  4017c0:	48 89 c7             	mov    %rax,%rdi
  4017c3:	e8 8d ff ff ff       	callq  401755 <blank_line>
  4017c8:	85 c0                	test   %eax,%eax
  4017ca:	75 c5                	jne    401791 <skip+0x1>
  4017cc:	48 89 d8             	mov    %rbx,%rax
  4017cf:	5b                   	pop    %rbx
  4017d0:	c3                   	retq   

00000000004017d1 <send_msg>:
  4017d1:	48 81 ec 18 40 00 00 	sub    $0x4018,%rsp
  4017d8:	41 89 f8             	mov    %edi,%r8d
  4017db:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4017e2:	00 00 
  4017e4:	48 89 84 24 08 40 00 	mov    %rax,0x4008(%rsp)
  4017eb:	00 
  4017ec:	31 c0                	xor    %eax,%eax
  4017ee:	8b 35 b8 33 20 00    	mov    0x2033b8(%rip),%esi        # 604bac <num_input_strings>
  4017f4:	8d 46 ff             	lea    -0x1(%rsi),%eax
  4017f7:	48 98                	cltq   
  4017f9:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
  4017fd:	48 c1 e2 04          	shl    $0x4,%rdx
  401801:	48 81 c2 c0 4b 60 00 	add    $0x604bc0,%rdx
  401808:	b8 00 00 00 00       	mov    $0x0,%eax
  40180d:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  401814:	48 89 d7             	mov    %rdx,%rdi
  401817:	f2 ae                	repnz scas %es:(%rdi),%al
  401819:	48 89 c8             	mov    %rcx,%rax
  40181c:	48 f7 d0             	not    %rax
  40181f:	48 83 c0 63          	add    $0x63,%rax
  401823:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
  401829:	77 78                	ja     4018a3 <send_msg+0xd2>
  40182b:	45 85 c0             	test   %r8d,%r8d
  40182e:	b8 0c 2b 40 00       	mov    $0x402b0c,%eax
  401833:	41 b9 04 2b 40 00    	mov    $0x402b04,%r9d
  401839:	4c 0f 44 c8          	cmove  %rax,%r9
  40183d:	52                   	push   %rdx
  40183e:	56                   	push   %rsi
  40183f:	44 8b 05 1a 2f 20 00 	mov    0x202f1a(%rip),%r8d        # 604760 <bomb_id>
  401846:	b9 15 2b 40 00       	mov    $0x402b15,%ecx
  40184b:	ba 00 20 00 00       	mov    $0x2000,%edx
  401850:	be 01 00 00 00       	mov    $0x1,%esi
  401855:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  40185a:	b8 00 00 00 00       	mov    $0x0,%eax
  40185f:	e8 bc f4 ff ff       	callq  400d20 <__sprintf_chk@plt>
  401864:	48 8d 8c 24 10 20 00 	lea    0x2010(%rsp),%rcx
  40186b:	00 
  40186c:	ba 00 00 00 00       	mov    $0x0,%edx
  401871:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  401876:	bf 60 43 60 00       	mov    $0x604360,%edi
  40187b:	e8 5e 0d 00 00       	callq  4025de <driver_post>
  401880:	48 83 c4 10          	add    $0x10,%rsp
  401884:	85 c0                	test   %eax,%eax
  401886:	78 39                	js     4018c1 <send_msg+0xf0>
  401888:	48 8b 84 24 08 40 00 	mov    0x4008(%rsp),%rax
  40188f:	00 
  401890:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401897:	00 00 
  401899:	75 3d                	jne    4018d8 <send_msg+0x107>
  40189b:	48 81 c4 18 40 00 00 	add    $0x4018,%rsp
  4018a2:	c3                   	retq   
  4018a3:	be 08 2a 40 00       	mov    $0x402a08,%esi
  4018a8:	bf 01 00 00 00       	mov    $0x1,%edi
  4018ad:	b8 00 00 00 00       	mov    $0x0,%eax
  4018b2:	e8 e9 f3 ff ff       	callq  400ca0 <__printf_chk@plt>
  4018b7:	bf 08 00 00 00       	mov    $0x8,%edi
  4018bc:	e8 0f f4 ff ff       	callq  400cd0 <exit@plt>
  4018c1:	48 8d bc 24 00 20 00 	lea    0x2000(%rsp),%rdi
  4018c8:	00 
  4018c9:	e8 e2 f2 ff ff       	callq  400bb0 <puts@plt>
  4018ce:	bf 00 00 00 00       	mov    $0x0,%edi
  4018d3:	e8 f8 f3 ff ff       	callq  400cd0 <exit@plt>
  4018d8:	e8 f3 f2 ff ff       	callq  400bd0 <__stack_chk_fail@plt>

00000000004018dd <explode_bomb>:
  4018dd:	48 83 ec 08          	sub    $0x8,%rsp
  4018e1:	bf 21 2b 40 00       	mov    $0x402b21,%edi
  4018e6:	e8 c5 f2 ff ff       	callq  400bb0 <puts@plt>
  4018eb:	bf 2a 2b 40 00       	mov    $0x402b2a,%edi
  4018f0:	e8 bb f2 ff ff       	callq  400bb0 <puts@plt>
  4018f5:	bf 00 00 00 00       	mov    $0x0,%edi
  4018fa:	e8 d2 fe ff ff       	callq  4017d1 <send_msg>
  4018ff:	bf 30 2a 40 00       	mov    $0x402a30,%edi
  401904:	e8 a7 f2 ff ff       	callq  400bb0 <puts@plt>
  401909:	bf 08 00 00 00       	mov    $0x8,%edi
  40190e:	e8 bd f3 ff ff       	callq  400cd0 <exit@plt>

0000000000401913 <read_six_numbers>:
  401913:	48 83 ec 08          	sub    $0x8,%rsp
  401917:	48 89 f2             	mov    %rsi,%rdx
  40191a:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
  40191e:	48 8d 46 14          	lea    0x14(%rsi),%rax
  401922:	50                   	push   %rax
  401923:	48 8d 46 10          	lea    0x10(%rsi),%rax
  401927:	50                   	push   %rax
  401928:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
  40192c:	4c 8d 46 08          	lea    0x8(%rsi),%r8
  401930:	be 41 2b 40 00       	mov    $0x402b41,%esi
  401935:	b8 00 00 00 00       	mov    $0x0,%eax
  40193a:	e8 51 f3 ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  40193f:	48 83 c4 10          	add    $0x10,%rsp
  401943:	83 f8 05             	cmp    $0x5,%eax
  401946:	7e 05                	jle    40194d <read_six_numbers+0x3a>
  401948:	48 83 c4 08          	add    $0x8,%rsp
  40194c:	c3                   	retq   
  40194d:	e8 8b ff ff ff       	callq  4018dd <explode_bomb>

0000000000401952 <read_line>:
  401952:	48 83 ec 08          	sub    $0x8,%rsp
  401956:	b8 00 00 00 00       	mov    $0x0,%eax
  40195b:	e8 30 fe ff ff       	callq  401790 <skip>
  401960:	48 85 c0             	test   %rax,%rax
  401963:	74 63                	je     4019c8 <read_line+0x76>
  401965:	8b 35 41 32 20 00    	mov    0x203241(%rip),%esi        # 604bac <num_input_strings>
  40196b:	48 63 c6             	movslq %esi,%rax
  40196e:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
  401972:	48 c1 e2 04          	shl    $0x4,%rdx
  401976:	48 81 c2 c0 4b 60 00 	add    $0x604bc0,%rdx
  40197d:	b8 00 00 00 00       	mov    $0x0,%eax
  401982:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  401989:	48 89 d7             	mov    %rdx,%rdi
  40198c:	f2 ae                	repnz scas %es:(%rdi),%al
  40198e:	48 f7 d1             	not    %rcx
  401991:	48 83 e9 01          	sub    $0x1,%rcx
  401995:	83 f9 4e             	cmp    $0x4e,%ecx
  401998:	0f 8f 9c 00 00 00    	jg     401a3a <read_line+0xe8>
  40199e:	83 e9 01             	sub    $0x1,%ecx
  4019a1:	48 63 c9             	movslq %ecx,%rcx
  4019a4:	48 63 c6             	movslq %esi,%rax
  4019a7:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
  4019ab:	48 c1 e0 04          	shl    $0x4,%rax
  4019af:	c6 84 01 c0 4b 60 00 	movb   $0x0,0x604bc0(%rcx,%rax,1)
  4019b6:	00 
  4019b7:	8d 46 01             	lea    0x1(%rsi),%eax
  4019ba:	89 05 ec 31 20 00    	mov    %eax,0x2031ec(%rip)        # 604bac <num_input_strings>
  4019c0:	48 89 d0             	mov    %rdx,%rax
  4019c3:	48 83 c4 08          	add    $0x8,%rsp
  4019c7:	c3                   	retq   
  4019c8:	48 8b 05 c1 31 20 00 	mov    0x2031c1(%rip),%rax        # 604b90 <stdin@@GLIBC_2.2.5>
  4019cf:	48 39 05 da 31 20 00 	cmp    %rax,0x2031da(%rip)        # 604bb0 <infile>
  4019d6:	74 44                	je     401a1c <read_line+0xca>
  4019d8:	bf 71 2b 40 00       	mov    $0x402b71,%edi
  4019dd:	e8 8e f1 ff ff       	callq  400b70 <getenv@plt>
  4019e2:	48 85 c0             	test   %rax,%rax
  4019e5:	75 49                	jne    401a30 <read_line+0xde>
  4019e7:	48 8b 05 a2 31 20 00 	mov    0x2031a2(%rip),%rax        # 604b90 <stdin@@GLIBC_2.2.5>
  4019ee:	48 89 05 bb 31 20 00 	mov    %rax,0x2031bb(%rip)        # 604bb0 <infile>
  4019f5:	b8 00 00 00 00       	mov    $0x0,%eax
  4019fa:	e8 91 fd ff ff       	callq  401790 <skip>
  4019ff:	48 85 c0             	test   %rax,%rax
  401a02:	0f 85 5d ff ff ff    	jne    401965 <read_line+0x13>
  401a08:	bf 53 2b 40 00       	mov    $0x402b53,%edi
  401a0d:	e8 9e f1 ff ff       	callq  400bb0 <puts@plt>
  401a12:	bf 00 00 00 00       	mov    $0x0,%edi
  401a17:	e8 b4 f2 ff ff       	callq  400cd0 <exit@plt>
  401a1c:	bf 53 2b 40 00       	mov    $0x402b53,%edi
  401a21:	e8 8a f1 ff ff       	callq  400bb0 <puts@plt>
  401a26:	bf 08 00 00 00       	mov    $0x8,%edi
  401a2b:	e8 a0 f2 ff ff       	callq  400cd0 <exit@plt>
  401a30:	bf 00 00 00 00       	mov    $0x0,%edi
  401a35:	e8 96 f2 ff ff       	callq  400cd0 <exit@plt>
  401a3a:	bf 7c 2b 40 00       	mov    $0x402b7c,%edi
  401a3f:	e8 6c f1 ff ff       	callq  400bb0 <puts@plt>
  401a44:	8b 05 62 31 20 00    	mov    0x203162(%rip),%eax        # 604bac <num_input_strings>
  401a4a:	8d 50 01             	lea    0x1(%rax),%edx
  401a4d:	89 15 59 31 20 00    	mov    %edx,0x203159(%rip)        # 604bac <num_input_strings>
  401a53:	48 98                	cltq   
  401a55:	48 6b c0 50          	imul   $0x50,%rax,%rax
  401a59:	48 bf 2a 2a 2a 74 72 	movabs $0x636e7572742a2a2a,%rdi
  401a60:	75 6e 63 
  401a63:	48 89 b8 c0 4b 60 00 	mov    %rdi,0x604bc0(%rax)
  401a6a:	48 bf 61 74 65 64 2a 	movabs $0x2a2a2a64657461,%rdi
  401a71:	2a 2a 00 
  401a74:	48 89 b8 c8 4b 60 00 	mov    %rdi,0x604bc8(%rax)
  401a7b:	e8 5d fe ff ff       	callq  4018dd <explode_bomb>

0000000000401a80 <phase_defused>:
  401a80:	48 83 ec 08          	sub    $0x8,%rsp
  401a84:	bf 01 00 00 00       	mov    $0x1,%edi
  401a89:	e8 43 fd ff ff       	callq  4017d1 <send_msg>
  401a8e:	83 3d 17 31 20 00 09 	cmpl   $0x9,0x203117(%rip)        # 604bac <num_input_strings>
  401a95:	74 05                	je     401a9c <phase_defused+0x1c>
  401a97:	48 83 c4 08          	add    $0x8,%rsp
  401a9b:	c3                   	retq   
  401a9c:	bf 58 2a 40 00       	mov    $0x402a58,%edi
  401aa1:	e8 0a f1 ff ff       	callq  400bb0 <puts@plt>
  401aa6:	bf 88 2a 40 00       	mov    $0x402a88,%edi
  401aab:	e8 00 f1 ff ff       	callq  400bb0 <puts@plt>
  401ab0:	eb e5                	jmp    401a97 <phase_defused+0x17>

0000000000401ab2 <sigalrm_handler>:
  401ab2:	48 83 ec 08          	sub    $0x8,%rsp
  401ab6:	b9 00 00 00 00       	mov    $0x0,%ecx
  401abb:	ba 00 2f 40 00       	mov    $0x402f00,%edx
  401ac0:	be 01 00 00 00       	mov    $0x1,%esi
  401ac5:	48 8b 3d d4 30 20 00 	mov    0x2030d4(%rip),%rdi        # 604ba0 <stderr@@GLIBC_2.2.5>
  401acc:	b8 00 00 00 00       	mov    $0x0,%eax
  401ad1:	e8 1a f2 ff ff       	callq  400cf0 <__fprintf_chk@plt>
  401ad6:	bf 01 00 00 00       	mov    $0x1,%edi
  401adb:	e8 f0 f1 ff ff       	callq  400cd0 <exit@plt>

0000000000401ae0 <rio_readlineb>:
  401ae0:	41 56                	push   %r14
  401ae2:	41 55                	push   %r13
  401ae4:	41 54                	push   %r12
  401ae6:	55                   	push   %rbp
  401ae7:	53                   	push   %rbx
  401ae8:	48 89 fb             	mov    %rdi,%rbx
  401aeb:	49 89 d6             	mov    %rdx,%r14
  401aee:	49 89 f5             	mov    %rsi,%r13
  401af1:	41 bc 01 00 00 00    	mov    $0x1,%r12d
  401af7:	48 8d 6f 10          	lea    0x10(%rdi),%rbp
  401afb:	48 83 fa 01          	cmp    $0x1,%rdx
  401aff:	77 0c                	ja     401b0d <rio_readlineb+0x2d>
  401b01:	eb 5f                	jmp    401b62 <rio_readlineb+0x82>
  401b03:	e8 88 f0 ff ff       	callq  400b90 <__errno_location@plt>
  401b08:	83 38 04             	cmpl   $0x4,(%rax)
  401b0b:	75 66                	jne    401b73 <rio_readlineb+0x93>
  401b0d:	8b 43 04             	mov    0x4(%rbx),%eax
  401b10:	85 c0                	test   %eax,%eax
  401b12:	7f 20                	jg     401b34 <rio_readlineb+0x54>
  401b14:	ba 00 20 00 00       	mov    $0x2000,%edx
  401b19:	48 89 ee             	mov    %rbp,%rsi
  401b1c:	8b 3b                	mov    (%rbx),%edi
  401b1e:	e8 dd f0 ff ff       	callq  400c00 <read@plt>
  401b23:	89 43 04             	mov    %eax,0x4(%rbx)
  401b26:	85 c0                	test   %eax,%eax
  401b28:	78 d9                	js     401b03 <rio_readlineb+0x23>
  401b2a:	85 c0                	test   %eax,%eax
  401b2c:	74 4e                	je     401b7c <rio_readlineb+0x9c>
  401b2e:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
  401b32:	eb d9                	jmp    401b0d <rio_readlineb+0x2d>
  401b34:	48 8b 53 08          	mov    0x8(%rbx),%rdx
  401b38:	0f b6 0a             	movzbl (%rdx),%ecx
  401b3b:	48 83 c2 01          	add    $0x1,%rdx
  401b3f:	48 89 53 08          	mov    %rdx,0x8(%rbx)
  401b43:	83 e8 01             	sub    $0x1,%eax
  401b46:	89 43 04             	mov    %eax,0x4(%rbx)
  401b49:	49 83 c5 01          	add    $0x1,%r13
  401b4d:	41 88 4d ff          	mov    %cl,-0x1(%r13)
  401b51:	80 f9 0a             	cmp    $0xa,%cl
  401b54:	74 0c                	je     401b62 <rio_readlineb+0x82>
  401b56:	41 83 c4 01          	add    $0x1,%r12d
  401b5a:	49 63 c4             	movslq %r12d,%rax
  401b5d:	4c 39 f0             	cmp    %r14,%rax
  401b60:	72 ab                	jb     401b0d <rio_readlineb+0x2d>
  401b62:	41 c6 45 00 00       	movb   $0x0,0x0(%r13)
  401b67:	49 63 c4             	movslq %r12d,%rax
  401b6a:	5b                   	pop    %rbx
  401b6b:	5d                   	pop    %rbp
  401b6c:	41 5c                	pop    %r12
  401b6e:	41 5d                	pop    %r13
  401b70:	41 5e                	pop    %r14
  401b72:	c3                   	retq   
  401b73:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  401b7a:	eb 05                	jmp    401b81 <rio_readlineb+0xa1>
  401b7c:	b8 00 00 00 00       	mov    $0x0,%eax
  401b81:	85 c0                	test   %eax,%eax
  401b83:	75 0d                	jne    401b92 <rio_readlineb+0xb2>
  401b85:	41 83 fc 01          	cmp    $0x1,%r12d
  401b89:	75 d7                	jne    401b62 <rio_readlineb+0x82>
  401b8b:	b8 00 00 00 00       	mov    $0x0,%eax
  401b90:	eb d8                	jmp    401b6a <rio_readlineb+0x8a>
  401b92:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  401b99:	eb cf                	jmp    401b6a <rio_readlineb+0x8a>

0000000000401b9b <submitr>:
  401b9b:	41 57                	push   %r15
  401b9d:	41 56                	push   %r14
  401b9f:	41 55                	push   %r13
  401ba1:	41 54                	push   %r12
  401ba3:	55                   	push   %rbp
  401ba4:	53                   	push   %rbx
  401ba5:	48 81 ec 68 a0 00 00 	sub    $0xa068,%rsp
  401bac:	48 89 fd             	mov    %rdi,%rbp
  401baf:	41 89 f5             	mov    %esi,%r13d
  401bb2:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
  401bb7:	48 89 4c 24 10       	mov    %rcx,0x10(%rsp)
  401bbc:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
  401bc1:	4c 89 cb             	mov    %r9,%rbx
  401bc4:	4c 8b bc 24 a0 a0 00 	mov    0xa0a0(%rsp),%r15
  401bcb:	00 
  401bcc:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401bd3:	00 00 
  401bd5:	48 89 84 24 58 a0 00 	mov    %rax,0xa058(%rsp)
  401bdc:	00 
  401bdd:	31 c0                	xor    %eax,%eax
  401bdf:	c7 44 24 2c 00 00 00 	movl   $0x0,0x2c(%rsp)
  401be6:	00 
  401be7:	ba 00 00 00 00       	mov    $0x0,%edx
  401bec:	be 01 00 00 00       	mov    $0x1,%esi
  401bf1:	bf 02 00 00 00       	mov    $0x2,%edi
  401bf6:	e8 35 f1 ff ff       	callq  400d30 <socket@plt>
  401bfb:	85 c0                	test   %eax,%eax
  401bfd:	0f 88 19 01 00 00    	js     401d1c <submitr+0x181>
  401c03:	41 89 c4             	mov    %eax,%r12d
  401c06:	48 89 ef             	mov    %rbp,%rdi
  401c09:	e8 32 f0 ff ff       	callq  400c40 <gethostbyname@plt>
  401c0e:	48 85 c0             	test   %rax,%rax
  401c11:	0f 84 55 01 00 00    	je     401d6c <submitr+0x1d1>
  401c17:	48 c7 44 24 30 00 00 	movq   $0x0,0x30(%rsp)
  401c1e:	00 00 
  401c20:	48 c7 44 24 38 00 00 	movq   $0x0,0x38(%rsp)
  401c27:	00 00 
  401c29:	66 c7 44 24 30 02 00 	movw   $0x2,0x30(%rsp)
  401c30:	48 63 50 14          	movslq 0x14(%rax),%rdx
  401c34:	48 8b 40 18          	mov    0x18(%rax),%rax
  401c38:	48 8d 7c 24 34       	lea    0x34(%rsp),%rdi
  401c3d:	b9 0c 00 00 00       	mov    $0xc,%ecx
  401c42:	48 8b 30             	mov    (%rax),%rsi
  401c45:	e8 06 f0 ff ff       	callq  400c50 <__memmove_chk@plt>
  401c4a:	66 41 c1 cd 08       	ror    $0x8,%r13w
  401c4f:	66 44 89 6c 24 32    	mov    %r13w,0x32(%rsp)
  401c55:	ba 10 00 00 00       	mov    $0x10,%edx
  401c5a:	48 8d 74 24 30       	lea    0x30(%rsp),%rsi
  401c5f:	44 89 e7             	mov    %r12d,%edi
  401c62:	e8 79 f0 ff ff       	callq  400ce0 <connect@plt>
  401c67:	85 c0                	test   %eax,%eax
  401c69:	0f 88 68 01 00 00    	js     401dd7 <submitr+0x23c>
  401c6f:	49 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%r9
  401c76:	b8 00 00 00 00       	mov    $0x0,%eax
  401c7b:	4c 89 c9             	mov    %r9,%rcx
  401c7e:	48 89 df             	mov    %rbx,%rdi
  401c81:	f2 ae                	repnz scas %es:(%rdi),%al
  401c83:	48 89 ce             	mov    %rcx,%rsi
  401c86:	48 f7 d6             	not    %rsi
  401c89:	4c 89 c9             	mov    %r9,%rcx
  401c8c:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  401c91:	f2 ae                	repnz scas %es:(%rdi),%al
  401c93:	49 89 c8             	mov    %rcx,%r8
  401c96:	4c 89 c9             	mov    %r9,%rcx
  401c99:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
  401c9e:	f2 ae                	repnz scas %es:(%rdi),%al
  401ca0:	48 89 ca             	mov    %rcx,%rdx
  401ca3:	48 f7 d2             	not    %rdx
  401ca6:	4c 89 c9             	mov    %r9,%rcx
  401ca9:	48 8b 7c 24 18       	mov    0x18(%rsp),%rdi
  401cae:	f2 ae                	repnz scas %es:(%rdi),%al
  401cb0:	4c 29 c2             	sub    %r8,%rdx
  401cb3:	48 29 ca             	sub    %rcx,%rdx
  401cb6:	48 8d 44 76 fd       	lea    -0x3(%rsi,%rsi,2),%rax
  401cbb:	48 8d 44 02 7b       	lea    0x7b(%rdx,%rax,1),%rax
  401cc0:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
  401cc6:	0f 87 68 01 00 00    	ja     401e34 <submitr+0x299>
  401ccc:	48 8d 94 24 50 40 00 	lea    0x4050(%rsp),%rdx
  401cd3:	00 
  401cd4:	b9 00 04 00 00       	mov    $0x400,%ecx
  401cd9:	b8 00 00 00 00       	mov    $0x0,%eax
  401cde:	48 89 d7             	mov    %rdx,%rdi
  401ce1:	f3 48 ab             	rep stos %rax,%es:(%rdi)
  401ce4:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  401ceb:	48 89 df             	mov    %rbx,%rdi
  401cee:	f2 ae                	repnz scas %es:(%rdi),%al
  401cf0:	48 89 c8             	mov    %rcx,%rax
  401cf3:	48 f7 d0             	not    %rax
  401cf6:	48 83 e8 01          	sub    $0x1,%rax
  401cfa:	85 c0                	test   %eax,%eax
  401cfc:	0f 84 51 06 00 00    	je     402353 <submitr+0x7b8>
  401d02:	8d 40 ff             	lea    -0x1(%rax),%eax
  401d05:	4c 8d 74 03 01       	lea    0x1(%rbx,%rax,1),%r14
  401d0a:	48 89 d5             	mov    %rdx,%rbp
  401d0d:	49 bd d9 ff 00 00 00 	movabs $0x2000000000ffd9,%r13
  401d14:	00 20 00 
  401d17:	e9 a6 01 00 00       	jmpq   401ec2 <submitr+0x327>
  401d1c:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  401d23:	3a 20 43 
  401d26:	49 89 07             	mov    %rax,(%r15)
  401d29:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  401d30:	20 75 6e 
  401d33:	49 89 47 08          	mov    %rax,0x8(%r15)
  401d37:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  401d3e:	74 6f 20 
  401d41:	49 89 47 10          	mov    %rax,0x10(%r15)
  401d45:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  401d4c:	65 20 73 
  401d4f:	49 89 47 18          	mov    %rax,0x18(%r15)
  401d53:	41 c7 47 20 6f 63 6b 	movl   $0x656b636f,0x20(%r15)
  401d5a:	65 
  401d5b:	66 41 c7 47 24 74 00 	movw   $0x74,0x24(%r15)
  401d62:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401d67:	e9 be 04 00 00       	jmpq   40222a <submitr+0x68f>
  401d6c:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  401d73:	3a 20 44 
  401d76:	49 89 07             	mov    %rax,(%r15)
  401d79:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  401d80:	20 75 6e 
  401d83:	49 89 47 08          	mov    %rax,0x8(%r15)
  401d87:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  401d8e:	74 6f 20 
  401d91:	49 89 47 10          	mov    %rax,0x10(%r15)
  401d95:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  401d9c:	76 65 20 
  401d9f:	49 89 47 18          	mov    %rax,0x18(%r15)
  401da3:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  401daa:	72 20 61 
  401dad:	49 89 47 20          	mov    %rax,0x20(%r15)
  401db1:	41 c7 47 28 64 64 72 	movl   $0x65726464,0x28(%r15)
  401db8:	65 
  401db9:	66 41 c7 47 2c 73 73 	movw   $0x7373,0x2c(%r15)
  401dc0:	41 c6 47 2e 00       	movb   $0x0,0x2e(%r15)
  401dc5:	44 89 e7             	mov    %r12d,%edi
  401dc8:	e8 23 ee ff ff       	callq  400bf0 <close@plt>
  401dcd:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401dd2:	e9 53 04 00 00       	jmpq   40222a <submitr+0x68f>
  401dd7:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
  401dde:	3a 20 55 
  401de1:	49 89 07             	mov    %rax,(%r15)
  401de4:	48 b8 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rax
  401deb:	20 74 6f 
  401dee:	49 89 47 08          	mov    %rax,0x8(%r15)
  401df2:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
  401df9:	65 63 74 
  401dfc:	49 89 47 10          	mov    %rax,0x10(%r15)
  401e00:	48 b8 20 74 6f 20 74 	movabs $0x20656874206f7420,%rax
  401e07:	68 65 20 
  401e0a:	49 89 47 18          	mov    %rax,0x18(%r15)
  401e0e:	41 c7 47 20 73 65 72 	movl   $0x76726573,0x20(%r15)
  401e15:	76 
  401e16:	66 41 c7 47 24 65 72 	movw   $0x7265,0x24(%r15)
  401e1d:	41 c6 47 26 00       	movb   $0x0,0x26(%r15)
  401e22:	44 89 e7             	mov    %r12d,%edi
  401e25:	e8 c6 ed ff ff       	callq  400bf0 <close@plt>
  401e2a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401e2f:	e9 f6 03 00 00       	jmpq   40222a <submitr+0x68f>
  401e34:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  401e3b:	3a 20 52 
  401e3e:	49 89 07             	mov    %rax,(%r15)
  401e41:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  401e48:	20 73 74 
  401e4b:	49 89 47 08          	mov    %rax,0x8(%r15)
  401e4f:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
  401e56:	74 6f 6f 
  401e59:	49 89 47 10          	mov    %rax,0x10(%r15)
  401e5d:	48 b8 20 6c 61 72 67 	movabs $0x202e656772616c20,%rax
  401e64:	65 2e 20 
  401e67:	49 89 47 18          	mov    %rax,0x18(%r15)
  401e6b:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
  401e72:	61 73 65 
  401e75:	49 89 47 20          	mov    %rax,0x20(%r15)
  401e79:	48 b8 20 53 55 42 4d 	movabs $0x5254494d42555320,%rax
  401e80:	49 54 52 
  401e83:	49 89 47 28          	mov    %rax,0x28(%r15)
  401e87:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
  401e8e:	55 46 00 
  401e91:	49 89 47 30          	mov    %rax,0x30(%r15)
  401e95:	44 89 e7             	mov    %r12d,%edi
  401e98:	e8 53 ed ff ff       	callq  400bf0 <close@plt>
  401e9d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401ea2:	e9 83 03 00 00       	jmpq   40222a <submitr+0x68f>
  401ea7:	49 0f a3 c5          	bt     %rax,%r13
  401eab:	73 21                	jae    401ece <submitr+0x333>
  401ead:	44 88 45 00          	mov    %r8b,0x0(%rbp)
  401eb1:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  401eb5:	48 83 c3 01          	add    $0x1,%rbx
  401eb9:	49 39 de             	cmp    %rbx,%r14
  401ebc:	0f 84 91 04 00 00    	je     402353 <submitr+0x7b8>
  401ec2:	44 0f b6 03          	movzbl (%rbx),%r8d
  401ec6:	41 8d 40 d6          	lea    -0x2a(%r8),%eax
  401eca:	3c 35                	cmp    $0x35,%al
  401ecc:	76 d9                	jbe    401ea7 <submitr+0x30c>
  401ece:	44 89 c0             	mov    %r8d,%eax
  401ed1:	83 e0 df             	and    $0xffffffdf,%eax
  401ed4:	83 e8 41             	sub    $0x41,%eax
  401ed7:	3c 19                	cmp    $0x19,%al
  401ed9:	76 d2                	jbe    401ead <submitr+0x312>
  401edb:	41 80 f8 20          	cmp    $0x20,%r8b
  401edf:	74 61                	je     401f42 <submitr+0x3a7>
  401ee1:	41 8d 40 e0          	lea    -0x20(%r8),%eax
  401ee5:	3c 5f                	cmp    $0x5f,%al
  401ee7:	76 0a                	jbe    401ef3 <submitr+0x358>
  401ee9:	41 80 f8 09          	cmp    $0x9,%r8b
  401eed:	0f 85 d3 03 00 00    	jne    4022c6 <submitr+0x72b>
  401ef3:	45 0f b6 c0          	movzbl %r8b,%r8d
  401ef7:	b9 d0 2f 40 00       	mov    $0x402fd0,%ecx
  401efc:	ba 08 00 00 00       	mov    $0x8,%edx
  401f01:	be 01 00 00 00       	mov    $0x1,%esi
  401f06:	48 8d bc 24 50 80 00 	lea    0x8050(%rsp),%rdi
  401f0d:	00 
  401f0e:	b8 00 00 00 00       	mov    $0x0,%eax
  401f13:	e8 08 ee ff ff       	callq  400d20 <__sprintf_chk@plt>
  401f18:	0f b6 84 24 50 80 00 	movzbl 0x8050(%rsp),%eax
  401f1f:	00 
  401f20:	88 45 00             	mov    %al,0x0(%rbp)
  401f23:	0f b6 84 24 51 80 00 	movzbl 0x8051(%rsp),%eax
  401f2a:	00 
  401f2b:	88 45 01             	mov    %al,0x1(%rbp)
  401f2e:	0f b6 84 24 52 80 00 	movzbl 0x8052(%rsp),%eax
  401f35:	00 
  401f36:	88 45 02             	mov    %al,0x2(%rbp)
  401f39:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
  401f3d:	e9 73 ff ff ff       	jmpq   401eb5 <submitr+0x31a>
  401f42:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
  401f46:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  401f4a:	e9 66 ff ff ff       	jmpq   401eb5 <submitr+0x31a>
  401f4f:	48 01 c5             	add    %rax,%rbp
  401f52:	48 29 c3             	sub    %rax,%rbx
  401f55:	74 26                	je     401f7d <submitr+0x3e2>
  401f57:	48 89 da             	mov    %rbx,%rdx
  401f5a:	48 89 ee             	mov    %rbp,%rsi
  401f5d:	44 89 e7             	mov    %r12d,%edi
  401f60:	e8 5b ec ff ff       	callq  400bc0 <write@plt>
  401f65:	48 85 c0             	test   %rax,%rax
  401f68:	7f e5                	jg     401f4f <submitr+0x3b4>
  401f6a:	e8 21 ec ff ff       	callq  400b90 <__errno_location@plt>
  401f6f:	83 38 04             	cmpl   $0x4,(%rax)
  401f72:	0f 85 c5 00 00 00    	jne    40203d <submitr+0x4a2>
  401f78:	4c 89 f0             	mov    %r14,%rax
  401f7b:	eb d2                	jmp    401f4f <submitr+0x3b4>
  401f7d:	4d 85 ed             	test   %r13,%r13
  401f80:	0f 88 b7 00 00 00    	js     40203d <submitr+0x4a2>
  401f86:	44 89 64 24 40       	mov    %r12d,0x40(%rsp)
  401f8b:	c7 44 24 44 00 00 00 	movl   $0x0,0x44(%rsp)
  401f92:	00 
  401f93:	48 8d 44 24 50       	lea    0x50(%rsp),%rax
  401f98:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  401f9d:	ba 00 20 00 00       	mov    $0x2000,%edx
  401fa2:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  401fa9:	00 
  401faa:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  401faf:	e8 2c fb ff ff       	callq  401ae0 <rio_readlineb>
  401fb4:	48 85 c0             	test   %rax,%rax
  401fb7:	0f 8e df 00 00 00    	jle    40209c <submitr+0x501>
  401fbd:	4c 8d 84 24 50 80 00 	lea    0x8050(%rsp),%r8
  401fc4:	00 
  401fc5:	48 8d 4c 24 2c       	lea    0x2c(%rsp),%rcx
  401fca:	48 8d 94 24 50 60 00 	lea    0x6050(%rsp),%rdx
  401fd1:	00 
  401fd2:	be d7 2f 40 00       	mov    $0x402fd7,%esi
  401fd7:	48 8d bc 24 50 20 00 	lea    0x2050(%rsp),%rdi
  401fde:	00 
  401fdf:	b8 00 00 00 00       	mov    $0x0,%eax
  401fe4:	e8 a7 ec ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  401fe9:	44 8b 44 24 2c       	mov    0x2c(%rsp),%r8d
  401fee:	bb 0d 00 00 00       	mov    $0xd,%ebx
  401ff3:	bd 0a 00 00 00       	mov    $0xa,%ebp
  401ff8:	41 81 f8 c8 00 00 00 	cmp    $0xc8,%r8d
  401fff:	0f 84 99 01 00 00    	je     40219e <submitr+0x603>
  402005:	4c 8d 8c 24 50 80 00 	lea    0x8050(%rsp),%r9
  40200c:	00 
  40200d:	b9 28 2f 40 00       	mov    $0x402f28,%ecx
  402012:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
  402019:	be 01 00 00 00       	mov    $0x1,%esi
  40201e:	4c 89 ff             	mov    %r15,%rdi
  402021:	b8 00 00 00 00       	mov    $0x0,%eax
  402026:	e8 f5 ec ff ff       	callq  400d20 <__sprintf_chk@plt>
  40202b:	44 89 e7             	mov    %r12d,%edi
  40202e:	e8 bd eb ff ff       	callq  400bf0 <close@plt>
  402033:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402038:	e9 ed 01 00 00       	jmpq   40222a <submitr+0x68f>
  40203d:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402044:	3a 20 43 
  402047:	49 89 07             	mov    %rax,(%r15)
  40204a:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402051:	20 75 6e 
  402054:	49 89 47 08          	mov    %rax,0x8(%r15)
  402058:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  40205f:	74 6f 20 
  402062:	49 89 47 10          	mov    %rax,0x10(%r15)
  402066:	48 b8 77 72 69 74 65 	movabs $0x6f74206574697277,%rax
  40206d:	20 74 6f 
  402070:	49 89 47 18          	mov    %rax,0x18(%r15)
  402074:	48 b8 20 74 68 65 20 	movabs $0x7265732065687420,%rax
  40207b:	73 65 72 
  40207e:	49 89 47 20          	mov    %rax,0x20(%r15)
  402082:	41 c7 47 28 76 65 72 	movl   $0x726576,0x28(%r15)
  402089:	00 
  40208a:	44 89 e7             	mov    %r12d,%edi
  40208d:	e8 5e eb ff ff       	callq  400bf0 <close@plt>
  402092:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402097:	e9 8e 01 00 00       	jmpq   40222a <submitr+0x68f>
  40209c:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  4020a3:	3a 20 43 
  4020a6:	49 89 07             	mov    %rax,(%r15)
  4020a9:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  4020b0:	20 75 6e 
  4020b3:	49 89 47 08          	mov    %rax,0x8(%r15)
  4020b7:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  4020be:	74 6f 20 
  4020c1:	49 89 47 10          	mov    %rax,0x10(%r15)
  4020c5:	48 b8 72 65 61 64 20 	movabs $0x7269662064616572,%rax
  4020cc:	66 69 72 
  4020cf:	49 89 47 18          	mov    %rax,0x18(%r15)
  4020d3:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
  4020da:	61 64 65 
  4020dd:	49 89 47 20          	mov    %rax,0x20(%r15)
  4020e1:	48 b8 72 20 66 72 6f 	movabs $0x73206d6f72662072,%rax
  4020e8:	6d 20 73 
  4020eb:	49 89 47 28          	mov    %rax,0x28(%r15)
  4020ef:	41 c7 47 30 65 72 76 	movl   $0x65767265,0x30(%r15)
  4020f6:	65 
  4020f7:	66 41 c7 47 34 72 00 	movw   $0x72,0x34(%r15)
  4020fe:	44 89 e7             	mov    %r12d,%edi
  402101:	e8 ea ea ff ff       	callq  400bf0 <close@plt>
  402106:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40210b:	e9 1a 01 00 00       	jmpq   40222a <submitr+0x68f>
  402110:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402117:	3a 20 43 
  40211a:	49 89 07             	mov    %rax,(%r15)
  40211d:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402124:	20 75 6e 
  402127:	49 89 47 08          	mov    %rax,0x8(%r15)
  40212b:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402132:	74 6f 20 
  402135:	49 89 47 10          	mov    %rax,0x10(%r15)
  402139:	48 b8 72 65 61 64 20 	movabs $0x6165682064616572,%rax
  402140:	68 65 61 
  402143:	49 89 47 18          	mov    %rax,0x18(%r15)
  402147:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
  40214e:	66 72 6f 
  402151:	49 89 47 20          	mov    %rax,0x20(%r15)
  402155:	48 b8 6d 20 73 65 72 	movabs $0x726576726573206d,%rax
  40215c:	76 65 72 
  40215f:	49 89 47 28          	mov    %rax,0x28(%r15)
  402163:	41 c6 47 30 00       	movb   $0x0,0x30(%r15)
  402168:	44 89 e7             	mov    %r12d,%edi
  40216b:	e8 80 ea ff ff       	callq  400bf0 <close@plt>
  402170:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402175:	e9 b0 00 00 00       	jmpq   40222a <submitr+0x68f>
  40217a:	85 c0                	test   %eax,%eax
  40217c:	74 4c                	je     4021ca <submitr+0x62f>
  40217e:	ba 00 20 00 00       	mov    $0x2000,%edx
  402183:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  40218a:	00 
  40218b:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  402190:	e8 4b f9 ff ff       	callq  401ae0 <rio_readlineb>
  402195:	48 85 c0             	test   %rax,%rax
  402198:	0f 8e 72 ff ff ff    	jle    402110 <submitr+0x575>
  40219e:	0f b6 84 24 50 20 00 	movzbl 0x2050(%rsp),%eax
  4021a5:	00 
  4021a6:	89 d9                	mov    %ebx,%ecx
  4021a8:	29 c1                	sub    %eax,%ecx
  4021aa:	89 c8                	mov    %ecx,%eax
  4021ac:	75 cc                	jne    40217a <submitr+0x5df>
  4021ae:	0f b6 84 24 51 20 00 	movzbl 0x2051(%rsp),%eax
  4021b5:	00 
  4021b6:	89 ea                	mov    %ebp,%edx
  4021b8:	29 c2                	sub    %eax,%edx
  4021ba:	89 d0                	mov    %edx,%eax
  4021bc:	75 bc                	jne    40217a <submitr+0x5df>
  4021be:	0f b6 84 24 52 20 00 	movzbl 0x2052(%rsp),%eax
  4021c5:	00 
  4021c6:	f7 d8                	neg    %eax
  4021c8:	eb b0                	jmp    40217a <submitr+0x5df>
  4021ca:	ba 00 20 00 00       	mov    $0x2000,%edx
  4021cf:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  4021d6:	00 
  4021d7:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  4021dc:	e8 ff f8 ff ff       	callq  401ae0 <rio_readlineb>
  4021e1:	48 85 c0             	test   %rax,%rax
  4021e4:	7e 6d                	jle    402253 <submitr+0x6b8>
  4021e6:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  4021ed:	00 
  4021ee:	4c 89 ff             	mov    %r15,%rdi
  4021f1:	e8 aa e9 ff ff       	callq  400ba0 <strcpy@plt>
  4021f6:	44 89 e7             	mov    %r12d,%edi
  4021f9:	e8 f2 e9 ff ff       	callq  400bf0 <close@plt>
  4021fe:	41 0f b6 17          	movzbl (%r15),%edx
  402202:	b8 4f 00 00 00       	mov    $0x4f,%eax
  402207:	29 d0                	sub    %edx,%eax
  402209:	75 15                	jne    402220 <submitr+0x685>
  40220b:	41 0f b6 57 01       	movzbl 0x1(%r15),%edx
  402210:	b8 4b 00 00 00       	mov    $0x4b,%eax
  402215:	29 d0                	sub    %edx,%eax
  402217:	75 07                	jne    402220 <submitr+0x685>
  402219:	41 0f b6 47 02       	movzbl 0x2(%r15),%eax
  40221e:	f7 d8                	neg    %eax
  402220:	85 c0                	test   %eax,%eax
  402222:	0f 95 c0             	setne  %al
  402225:	0f b6 c0             	movzbl %al,%eax
  402228:	f7 d8                	neg    %eax
  40222a:	48 8b 8c 24 58 a0 00 	mov    0xa058(%rsp),%rcx
  402231:	00 
  402232:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  402239:	00 00 
  40223b:	0f 85 8b 01 00 00    	jne    4023cc <submitr+0x831>
  402241:	48 81 c4 68 a0 00 00 	add    $0xa068,%rsp
  402248:	5b                   	pop    %rbx
  402249:	5d                   	pop    %rbp
  40224a:	41 5c                	pop    %r12
  40224c:	41 5d                	pop    %r13
  40224e:	41 5e                	pop    %r14
  402250:	41 5f                	pop    %r15
  402252:	c3                   	retq   
  402253:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  40225a:	3a 20 43 
  40225d:	49 89 07             	mov    %rax,(%r15)
  402260:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402267:	20 75 6e 
  40226a:	49 89 47 08          	mov    %rax,0x8(%r15)
  40226e:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402275:	74 6f 20 
  402278:	49 89 47 10          	mov    %rax,0x10(%r15)
  40227c:	48 b8 72 65 61 64 20 	movabs $0x6174732064616572,%rax
  402283:	73 74 61 
  402286:	49 89 47 18          	mov    %rax,0x18(%r15)
  40228a:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
  402291:	65 73 73 
  402294:	49 89 47 20          	mov    %rax,0x20(%r15)
  402298:	48 b8 61 67 65 20 66 	movabs $0x6d6f726620656761,%rax
  40229f:	72 6f 6d 
  4022a2:	49 89 47 28          	mov    %rax,0x28(%r15)
  4022a6:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
  4022ad:	65 72 00 
  4022b0:	49 89 47 30          	mov    %rax,0x30(%r15)
  4022b4:	44 89 e7             	mov    %r12d,%edi
  4022b7:	e8 34 e9 ff ff       	callq  400bf0 <close@plt>
  4022bc:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4022c1:	e9 64 ff ff ff       	jmpq   40222a <submitr+0x68f>
  4022c6:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  4022cd:	3a 20 52 
  4022d0:	49 89 07             	mov    %rax,(%r15)
  4022d3:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  4022da:	20 73 74 
  4022dd:	49 89 47 08          	mov    %rax,0x8(%r15)
  4022e1:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
  4022e8:	63 6f 6e 
  4022eb:	49 89 47 10          	mov    %rax,0x10(%r15)
  4022ef:	48 b8 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rax
  4022f6:	20 61 6e 
  4022f9:	49 89 47 18          	mov    %rax,0x18(%r15)
  4022fd:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
  402304:	67 61 6c 
  402307:	49 89 47 20          	mov    %rax,0x20(%r15)
  40230b:	48 b8 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rax
  402312:	6e 70 72 
  402315:	49 89 47 28          	mov    %rax,0x28(%r15)
  402319:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
  402320:	6c 65 20 
  402323:	49 89 47 30          	mov    %rax,0x30(%r15)
  402327:	48 b8 63 68 61 72 61 	movabs $0x6574636172616863,%rax
  40232e:	63 74 65 
  402331:	49 89 47 38          	mov    %rax,0x38(%r15)
  402335:	66 41 c7 47 40 72 2e 	movw   $0x2e72,0x40(%r15)
  40233c:	41 c6 47 42 00       	movb   $0x0,0x42(%r15)
  402341:	44 89 e7             	mov    %r12d,%edi
  402344:	e8 a7 e8 ff ff       	callq  400bf0 <close@plt>
  402349:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40234e:	e9 d7 fe ff ff       	jmpq   40222a <submitr+0x68f>
  402353:	48 8d 9c 24 50 20 00 	lea    0x2050(%rsp),%rbx
  40235a:	00 
  40235b:	48 8d 84 24 50 40 00 	lea    0x4050(%rsp),%rax
  402362:	00 
  402363:	50                   	push   %rax
  402364:	ff 74 24 20          	pushq  0x20(%rsp)
  402368:	4c 8b 4c 24 20       	mov    0x20(%rsp),%r9
  40236d:	4c 8b 44 24 18       	mov    0x18(%rsp),%r8
  402372:	b9 58 2f 40 00       	mov    $0x402f58,%ecx
  402377:	ba 00 20 00 00       	mov    $0x2000,%edx
  40237c:	be 01 00 00 00       	mov    $0x1,%esi
  402381:	48 89 df             	mov    %rbx,%rdi
  402384:	b8 00 00 00 00       	mov    $0x0,%eax
  402389:	e8 92 e9 ff ff       	callq  400d20 <__sprintf_chk@plt>
  40238e:	b8 00 00 00 00       	mov    $0x0,%eax
  402393:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  40239a:	48 89 df             	mov    %rbx,%rdi
  40239d:	f2 ae                	repnz scas %es:(%rdi),%al
  40239f:	48 89 c8             	mov    %rcx,%rax
  4023a2:	48 f7 d0             	not    %rax
  4023a5:	4c 8d 68 ff          	lea    -0x1(%rax),%r13
  4023a9:	48 83 c4 10          	add    $0x10,%rsp
  4023ad:	4c 89 eb             	mov    %r13,%rbx
  4023b0:	48 8d ac 24 50 20 00 	lea    0x2050(%rsp),%rbp
  4023b7:	00 
  4023b8:	41 be 00 00 00 00    	mov    $0x0,%r14d
  4023be:	4d 85 ed             	test   %r13,%r13
  4023c1:	0f 85 90 fb ff ff    	jne    401f57 <submitr+0x3bc>
  4023c7:	e9 ba fb ff ff       	jmpq   401f86 <submitr+0x3eb>
  4023cc:	e8 ff e7 ff ff       	callq  400bd0 <__stack_chk_fail@plt>

00000000004023d1 <init_timeout>:
  4023d1:	85 ff                	test   %edi,%edi
  4023d3:	74 22                	je     4023f7 <init_timeout+0x26>
  4023d5:	53                   	push   %rbx
  4023d6:	89 fb                	mov    %edi,%ebx
  4023d8:	be b2 1a 40 00       	mov    $0x401ab2,%esi
  4023dd:	bf 0e 00 00 00       	mov    $0xe,%edi
  4023e2:	e8 49 e8 ff ff       	callq  400c30 <signal@plt>
  4023e7:	85 db                	test   %ebx,%ebx
  4023e9:	bf 00 00 00 00       	mov    $0x0,%edi
  4023ee:	0f 49 fb             	cmovns %ebx,%edi
  4023f1:	e8 ea e7 ff ff       	callq  400be0 <alarm@plt>
  4023f6:	5b                   	pop    %rbx
  4023f7:	f3 c3                	repz retq 

00000000004023f9 <init_driver>:
  4023f9:	55                   	push   %rbp
  4023fa:	53                   	push   %rbx
  4023fb:	48 83 ec 28          	sub    $0x28,%rsp
  4023ff:	48 89 fd             	mov    %rdi,%rbp
  402402:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  402409:	00 00 
  40240b:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  402410:	31 c0                	xor    %eax,%eax
  402412:	be 01 00 00 00       	mov    $0x1,%esi
  402417:	bf 0d 00 00 00       	mov    $0xd,%edi
  40241c:	e8 0f e8 ff ff       	callq  400c30 <signal@plt>
  402421:	be 01 00 00 00       	mov    $0x1,%esi
  402426:	bf 1d 00 00 00       	mov    $0x1d,%edi
  40242b:	e8 00 e8 ff ff       	callq  400c30 <signal@plt>
  402430:	be 01 00 00 00       	mov    $0x1,%esi
  402435:	bf 1d 00 00 00       	mov    $0x1d,%edi
  40243a:	e8 f1 e7 ff ff       	callq  400c30 <signal@plt>
  40243f:	ba 00 00 00 00       	mov    $0x0,%edx
  402444:	be 01 00 00 00       	mov    $0x1,%esi
  402449:	bf 02 00 00 00       	mov    $0x2,%edi
  40244e:	e8 dd e8 ff ff       	callq  400d30 <socket@plt>
  402453:	85 c0                	test   %eax,%eax
  402455:	0f 88 95 00 00 00    	js     4024f0 <init_driver+0xf7>
  40245b:	89 c3                	mov    %eax,%ebx
  40245d:	bf e8 2f 40 00       	mov    $0x402fe8,%edi
  402462:	e8 d9 e7 ff ff       	callq  400c40 <gethostbyname@plt>
  402467:	48 85 c0             	test   %rax,%rax
  40246a:	0f 84 cc 00 00 00    	je     40253c <init_driver+0x143>
  402470:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  402477:	00 
  402478:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  40247f:	00 00 
  402481:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
  402487:	48 63 50 14          	movslq 0x14(%rax),%rdx
  40248b:	48 8b 40 18          	mov    0x18(%rax),%rax
  40248f:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
  402494:	b9 0c 00 00 00       	mov    $0xc,%ecx
  402499:	48 8b 30             	mov    (%rax),%rsi
  40249c:	e8 af e7 ff ff       	callq  400c50 <__memmove_chk@plt>
  4024a1:	66 c7 44 24 02 3f 49 	movw   $0x493f,0x2(%rsp)
  4024a8:	ba 10 00 00 00       	mov    $0x10,%edx
  4024ad:	48 89 e6             	mov    %rsp,%rsi
  4024b0:	89 df                	mov    %ebx,%edi
  4024b2:	e8 29 e8 ff ff       	callq  400ce0 <connect@plt>
  4024b7:	85 c0                	test   %eax,%eax
  4024b9:	0f 88 e5 00 00 00    	js     4025a4 <init_driver+0x1ab>
  4024bf:	89 df                	mov    %ebx,%edi
  4024c1:	e8 2a e7 ff ff       	callq  400bf0 <close@plt>
  4024c6:	66 c7 45 00 4f 4b    	movw   $0x4b4f,0x0(%rbp)
  4024cc:	c6 45 02 00          	movb   $0x0,0x2(%rbp)
  4024d0:	b8 00 00 00 00       	mov    $0x0,%eax
  4024d5:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
  4024da:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  4024e1:	00 00 
  4024e3:	0f 85 f0 00 00 00    	jne    4025d9 <init_driver+0x1e0>
  4024e9:	48 83 c4 28          	add    $0x28,%rsp
  4024ed:	5b                   	pop    %rbx
  4024ee:	5d                   	pop    %rbp
  4024ef:	c3                   	retq   
  4024f0:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  4024f7:	3a 20 43 
  4024fa:	48 89 45 00          	mov    %rax,0x0(%rbp)
  4024fe:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402505:	20 75 6e 
  402508:	48 89 45 08          	mov    %rax,0x8(%rbp)
  40250c:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402513:	74 6f 20 
  402516:	48 89 45 10          	mov    %rax,0x10(%rbp)
  40251a:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  402521:	65 20 73 
  402524:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402528:	c7 45 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbp)
  40252f:	66 c7 45 24 74 00    	movw   $0x74,0x24(%rbp)
  402535:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40253a:	eb 99                	jmp    4024d5 <init_driver+0xdc>
  40253c:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  402543:	3a 20 44 
  402546:	48 89 45 00          	mov    %rax,0x0(%rbp)
  40254a:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  402551:	20 75 6e 
  402554:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402558:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  40255f:	74 6f 20 
  402562:	48 89 45 10          	mov    %rax,0x10(%rbp)
  402566:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  40256d:	76 65 20 
  402570:	48 89 45 18          	mov    %rax,0x18(%rbp)
  402574:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  40257b:	72 20 61 
  40257e:	48 89 45 20          	mov    %rax,0x20(%rbp)
  402582:	c7 45 28 64 64 72 65 	movl   $0x65726464,0x28(%rbp)
  402589:	66 c7 45 2c 73 73    	movw   $0x7373,0x2c(%rbp)
  40258f:	c6 45 2e 00          	movb   $0x0,0x2e(%rbp)
  402593:	89 df                	mov    %ebx,%edi
  402595:	e8 56 e6 ff ff       	callq  400bf0 <close@plt>
  40259a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40259f:	e9 31 ff ff ff       	jmpq   4024d5 <init_driver+0xdc>
  4025a4:	41 b8 e8 2f 40 00    	mov    $0x402fe8,%r8d
  4025aa:	b9 a8 2f 40 00       	mov    $0x402fa8,%ecx
  4025af:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
  4025b6:	be 01 00 00 00       	mov    $0x1,%esi
  4025bb:	48 89 ef             	mov    %rbp,%rdi
  4025be:	b8 00 00 00 00       	mov    $0x0,%eax
  4025c3:	e8 58 e7 ff ff       	callq  400d20 <__sprintf_chk@plt>
  4025c8:	89 df                	mov    %ebx,%edi
  4025ca:	e8 21 e6 ff ff       	callq  400bf0 <close@plt>
  4025cf:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4025d4:	e9 fc fe ff ff       	jmpq   4024d5 <init_driver+0xdc>
  4025d9:	e8 f2 e5 ff ff       	callq  400bd0 <__stack_chk_fail@plt>

00000000004025de <driver_post>:
  4025de:	53                   	push   %rbx
  4025df:	48 89 cb             	mov    %rcx,%rbx
  4025e2:	85 d2                	test   %edx,%edx
  4025e4:	75 17                	jne    4025fd <driver_post+0x1f>
  4025e6:	48 85 ff             	test   %rdi,%rdi
  4025e9:	74 05                	je     4025f0 <driver_post+0x12>
  4025eb:	80 3f 00             	cmpb   $0x0,(%rdi)
  4025ee:	75 34                	jne    402624 <driver_post+0x46>
  4025f0:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  4025f5:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  4025f9:	89 d0                	mov    %edx,%eax
  4025fb:	5b                   	pop    %rbx
  4025fc:	c3                   	retq   
  4025fd:	48 89 f2             	mov    %rsi,%rdx
  402600:	be fd 2f 40 00       	mov    $0x402ffd,%esi
  402605:	bf 01 00 00 00       	mov    $0x1,%edi
  40260a:	b8 00 00 00 00       	mov    $0x0,%eax
  40260f:	e8 8c e6 ff ff       	callq  400ca0 <__printf_chk@plt>
  402614:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  402619:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  40261d:	b8 00 00 00 00       	mov    $0x0,%eax
  402622:	eb d7                	jmp    4025fb <driver_post+0x1d>
  402624:	48 83 ec 08          	sub    $0x8,%rsp
  402628:	51                   	push   %rcx
  402629:	49 89 f1             	mov    %rsi,%r9
  40262c:	41 b8 14 30 40 00    	mov    $0x403014,%r8d
  402632:	48 89 f9             	mov    %rdi,%rcx
  402635:	ba 1b 30 40 00       	mov    $0x40301b,%edx
  40263a:	be 49 3f 00 00       	mov    $0x3f49,%esi
  40263f:	bf e8 2f 40 00       	mov    $0x402fe8,%edi
  402644:	e8 52 f5 ff ff       	callq  401b9b <submitr>
  402649:	48 83 c4 10          	add    $0x10,%rsp
  40264d:	eb ac                	jmp    4025fb <driver_post+0x1d>
  40264f:	90                   	nop

0000000000402650 <__libc_csu_init>:
  402650:	41 57                	push   %r15
  402652:	41 56                	push   %r14
  402654:	41 89 ff             	mov    %edi,%r15d
  402657:	41 55                	push   %r13
  402659:	41 54                	push   %r12
  40265b:	4c 8d 25 ae 17 20 00 	lea    0x2017ae(%rip),%r12        # 603e10 <__frame_dummy_init_array_entry>
  402662:	55                   	push   %rbp
  402663:	48 8d 2d ae 17 20 00 	lea    0x2017ae(%rip),%rbp        # 603e18 <__do_global_dtors_aux_fini_array_entry>
  40266a:	53                   	push   %rbx
  40266b:	49 89 f6             	mov    %rsi,%r14
  40266e:	49 89 d5             	mov    %rdx,%r13
  402671:	4c 29 e5             	sub    %r12,%rbp
  402674:	48 83 ec 08          	sub    $0x8,%rsp
  402678:	48 c1 fd 03          	sar    $0x3,%rbp
  40267c:	e8 b7 e4 ff ff       	callq  400b38 <_init>
  402681:	48 85 ed             	test   %rbp,%rbp
  402684:	74 20                	je     4026a6 <__libc_csu_init+0x56>
  402686:	31 db                	xor    %ebx,%ebx
  402688:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40268f:	00 
  402690:	4c 89 ea             	mov    %r13,%rdx
  402693:	4c 89 f6             	mov    %r14,%rsi
  402696:	44 89 ff             	mov    %r15d,%edi
  402699:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40269d:	48 83 c3 01          	add    $0x1,%rbx
  4026a1:	48 39 eb             	cmp    %rbp,%rbx
  4026a4:	75 ea                	jne    402690 <__libc_csu_init+0x40>
  4026a6:	48 83 c4 08          	add    $0x8,%rsp
  4026aa:	5b                   	pop    %rbx
  4026ab:	5d                   	pop    %rbp
  4026ac:	41 5c                	pop    %r12
  4026ae:	41 5d                	pop    %r13
  4026b0:	41 5e                	pop    %r14
  4026b2:	41 5f                	pop    %r15
  4026b4:	c3                   	retq   
  4026b5:	90                   	nop
  4026b6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4026bd:	00 00 00 

00000000004026c0 <__libc_csu_fini>:
  4026c0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000004026c4 <_fini>:
  4026c4:	48 83 ec 08          	sub    $0x8,%rsp
  4026c8:	48 83 c4 08          	add    $0x8,%rsp
  4026cc:	c3                   	retq   
