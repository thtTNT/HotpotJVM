//
// Created by 屠昊天 on 2022/3/12.
//

#ifndef HOTPOTJVM_INSTRUCTION_H
#define HOTPOTJVM_INSTRUCTION_H


#include "../../rtda/Frame.h"
#include "ByteCodeReader.h"

const int INS_CODE_NOPE = 0x00;
const int INS_CODE_ACONST_NULL = 0x01;
const int INS_CODE_ICONST_M1 = 0x02;
const int INS_CODE_ICONST_0 = 0x03;
const int INS_CODE_ICONST_1 = 0x04;
const int INS_CODE_ICONST_2 = 0x05;
const int INS_CODE_ICONST_3 = 0x06;
const int INS_CODE_ICONST_4 = 0x07;
const int INS_CODE_ICONST_5 = 0x08;
const int INS_CODE_LCONST_0 = 0x09;
const int INS_CODE_LCONST_1 = 0x0a;
const int INS_CODE_FCONST_0 = 0x0b;
const int INS_CODE_FCONST_1 = 0x0c;
const int INS_CODE_FCONST_2 = 0x0d;
const int INS_CODE_DCONST_0 = 0x0e;
const int INS_CODE_DCONST_1 = 0x0f;
const int INS_CODE_BIPUSH = 0x10;
const int INS_CODE_SIPUSH = 0x11;
const int INS_CODE_LDC = 0x12;
const int INS_CODE_LDC_W = 0x13;
const int INS_CODE_LDC2_W = 0x14;
const int INS_CODE_ILOAD = 0x15;
const int INS_CODE_LLOAD = 0x16;
const int INS_CODE_FLOAD = 0x17;
const int INS_CODE_DLOAD = 0x18;
const int INS_CODE_ALOAD = 0x19;
const int INS_CODE_ILOAD_0 = 0x1a;
const int INS_CODE_ILOAD_1 = 0x1b;
const int INS_CODE_ILOAD_2 = 0x1c;
const int INS_CODE_ILOAD_3 = 0x1d;
const int INS_CODE_LLOAD_0 = 0x1e;
const int INS_CODE_LLOAD_1 = 0x1f;
const int INS_CODE_LLOAD_2 = 0x20;
const int INS_CODE_LLOAD_3 = 0x21;
const int INS_CODE_FLOAD_0 = 0x22;
const int INS_CODE_FLOAD_1 = 0x23;
const int INS_CODE_FLOAD_2 = 0x24;
const int INS_CODE_FLOAD_3 = 0x25;
const int INS_CODE_DLOAD_0 = 0x26;
const int INS_CODE_DLOAD_1 = 0x27;
const int INS_CODE_DLOAD_2 = 0x28;
const int INS_CODE_DLOAD_3 = 0x29;
const int INS_CODE_ALOAD_0 = 0x2a;
const int INS_CODE_ALOAD_1 = 0x2b;
const int INS_CODE_ALOAD_2 = 0x2c;
const int INS_CODE_ALOAD_3 = 0x2d;
const int INS_CODE_IALOAD = 0x2e;
const int INS_CODE_LALOAD = 0x2f;
const int INS_CODE_FALOAD = 0x30;
const int INS_CODE_DALOAD = 0x31;
const int INS_CODE_AALOAD = 0x32;
const int INS_CODE_BALOAD = 0x33;
const int INS_CODE_CALOAD = 0x34;
const int INS_CODE_SALOAD = 0x35;
const int INS_CODE_ISTORE = 0x36;
const int INS_CODE_LSTORE = 0x37;
const int INS_CODE_FSTORE = 0x38;
const int INS_CODE_DSTORE = 0x39;
const int INS_CODE_ASTORE = 0x3a;
const int INS_CODE_ISTORE_0 = 0x3b;
const int INS_CODE_ISTORE_1 = 0x3c;
const int INS_CODE_ISTORE_2 = 0x3d;
const int INS_CODE_ISTORE_3 = 0x3e;
const int INS_CODE_LSTORE_0 = 0x3f;
const int INS_CODE_LSTORE_1 = 0x40;
const int INS_CODE_LSTORE_2 = 0x41;
const int INS_CODE_LSTORE_3 = 0x42;
const int INS_CODE_FSTORE_0 = 0x43;
const int INS_CODE_FSTORE_1 = 0x44;
const int INS_CODE_FSTORE_2 = 0x45;
const int INS_CODE_FSTORE_3 = 0x46;
const int INS_CODE_DSTORE_0 = 0x47;
const int INS_CODE_DSTORE_1 = 0x48;
const int INS_CODE_DSTORE_2 = 0x49;
const int INS_CODE_DSTORE_3 = 0x4a;
const int INS_CODE_ASTORE_0 = 0x4b;
const int INS_CODE_ASTORE_1 = 0x4c;
const int INS_CODE_ASTORE_2 = 0x4d;
const int INS_CODE_ASTORE_3 = 0x4e;
const int INS_CODE_IASTORE = 0x4f;
const int INS_CODE_LASTORE = 0x50;
const int INS_CODE_FASTORE = 0x51;
const int INS_CODE_DASTORE = 0x52;
const int INS_CODE_AASTORE = 0x53;
const int INS_CODE_BASTORE = 0x54;
const int INS_CODE_CASTORE = 0x55;
const int INS_CODE_SASTORE = 0x56;
const int INS_CODE_POP = 0x57;
const int INS_CODE_POP2 = 0x58;
const int INS_CODE_DUP = 0x59;
const int INS_CODE_DUP_X1 = 0x5a;
const int INS_CODE_DUP_X2 = 0x5b;
const int INS_CODE_DUP2 = 0x5c;
const int INS_CODE_DUP2_X1 = 0x5d;
const int INS_CODE_DUP2_X2 = 0x5e;
const int INS_CODE_SWAP = 0x5f;
const int INS_CODE_IADD = 0x60;
const int INS_CODE_LADD = 0x61;
const int INS_CODE_FADD = 0x62;
const int INS_CODE_DADD = 0x63;
const int INS_CODE_ISUB = 0x64;
const int INS_CODE_LSUB = 0x65;
const int INS_CODE_FSUB = 0x66;
const int INS_CODE_DSUB = 0x67;
const int INS_CODE_IMUL = 0x68;
const int INS_CODE_LMUL = 0x69;
const int INS_CODE_FMUL = 0x6a;
const int INS_CODE_DMUL = 0x6b;
const int INS_CODE_IDIV = 0x6c;
const int INS_CODE_LDIV = 0x6d;
const int INS_CODE_FDIV = 0x6e;
const int INS_CODE_DDIV = 0x6f;
const int INS_CODE_IREM = 0x70;
const int INS_CODE_LREM = 0x71;
const int INS_CODE_FREM = 0x72;
const int INS_CODE_DREM = 0x73;
const int INS_CODE_INEG = 0x74;
const int INS_CODE_LNEG = 0x75;
const int INS_CODE_FNEG = 0x76;
const int INS_CODE_DNEG = 0x77;
const int INS_CODE_ISHL = 0x78;
const int INS_CODE_LSHL = 0x79;
const int INS_CODE_ISHR = 0x7a;
const int INS_CODE_LSHR = 0x7b;
const int INS_CODE_IUSHR = 0x7c;
const int INS_CODE_LUSHR = 0x7d;
const int INS_CODE_IAND = 0x7e;
const int INS_CODE_LAND = 0x7f;
const int INS_CODE_IOR = 0x80;
const int INS_CODE_LOR = 0x81;
const int INS_CODE_IXOR = 0x82;
const int INS_CODE_LXOR = 0x83;
const int INS_CODE_IINC = 0x84;
const int INS_CODE_I2L = 0x85;
const int INS_CODE_I2F = 0x86;
const int INS_CODE_I2D = 0x87;
const int INS_CODE_L2I = 0x88;
const int INS_CODE_L2F = 0x89;
const int INS_CODE_L2D = 0x8a;
const int INS_CODE_F2I = 0x8b;
const int INS_CODE_F2L = 0x8c;
const int INS_CODE_F2D = 0x8d;
const int INS_CODE_D2I = 0x8e;
const int INS_CODE_D2L = 0x8f;
const int INS_CODE_D2F = 0x90;
const int INS_CODE_I2B = 0x91;
const int INS_CODE_I2C = 0x92;
const int INS_CODE_I2S = 0x93;
const int INS_CODE_LCMP = 0x94;
const int INS_CODE_FCMPL = 0x95;
const int INS_CODE_FCMPG = 0x96;
const int INS_CODE_DCMPL = 0x97;
const int INS_CODE_DCMPG = 0x98;
const int INS_CODE_IFEQ = 0x99;
const int INS_CODE_IFNE = 0x9a;
const int INS_CODE_IFLT = 0x9b;
const int INS_CODE_IFGE = 0x9c;
const int INS_CODE_IFGT = 0x9d;
const int INS_CODE_IFLE = 0x9e;
const int INS_CODE_IF_ICMPEQ = 0x9f;
const int INS_CODE_IF_ICMPNE = 0xa0;
const int INS_CODE_IF_ICMPLT = 0xa1;
const int INS_CODE_IF_ICMPGE = 0xa2;
const int INS_CODE_IF_ICMPGT = 0xa3;
const int INS_CODE_IF_ICMPLE = 0xa4;
const int INS_CODE_IF_ACMPEQ = 0xa5;
const int INS_CODE_IF_ACMPNE = 0xa6;
const int INS_CODE_GOTO = 0xa7;
const int INS_CODE_JSR = 0xa8;
const int INS_CODE_RET = 0xa9;
const int INS_CODE_TABLE_SWITCH = 0xaa;
const int INS_CODE_LOOKUP_SWITCH = 0xab;
const int INS_CODE_IRETURN = 0xac;
const int INS_CODE_LRETURN = 0xad;
const int INS_CODE_FRETURN = 0xae;
const int INS_CODE_DRETURN = 0xaf;
const int INS_CODE_ARETURN = 0xb0;
const int INS_CODE_RETURN = 0xb1;
const int INS_CODE_GETSTATIC = 0xb2;
const int INS_CODE_PUTSTATIC = 0xb3;
const int INS_CODE_GETFIELD = 0xb4;
const int INS_CODE_PUTFIELD = 0xb5;
const int INS_CODE_INVOKEVIRUAL = 0xb6;
const int INS_CODE_INVOKESPECIAL = 0xb7;
const int INS_CODE_INVOKESTATIC = 0xb8;
const int INS_CODE_INVOKEINTERFACE = 0xb9;
const int INS_CODE_INVOKEDYMATIC = 0xba;
const int INS_CODE_NEW = 0xbb;
const int INS_CODE_NEWARRAY = 0xbc;
const int INS_CODE_ANEWARRAY = 0xbd;
const int INS_CODE_ARRAYLENGTH = 0xbe;
const int INS_CODE_ATHROW = 0xbf;
const int INS_CODE_CHECKCAST = 0xc0;
const int INS_CODE_INSTANCEOF = 0xc1;
const int INS_CODE_MONITORENTER = 0xc2;
const int INS_CODE_MONITOREXIT = 0xc3;
const int INS_CODE_WIDE = 0xc4;
const int INS_CODE_MULTIANEWARRAY = 0xc5;
const int INS_CODE_IFNULL = 0xc6;
const int INS_CODE_IFNONNULL = 0xc7;
const int INS_CODE_GOTO_W = 0xc8;
const int INS_CODE_JSR_W = 0xc9;


class Instruction {
public:
    virtual void fetchOperands(ByteCodeReader *reader) = 0;

    virtual void execute(Frame *frame) = 0;
};

class NOPE : public Instruction {
    void fetchOperands(ByteCodeReader *reader) override {};

    void execute(Frame *frame) override {};
};

class NoOperandsInstruction : public Instruction {
    void fetchOperands(ByteCodeReader *reader) override;
};

class BranchInstruction : public Instruction {
public:
    int offset = 0;

    void fetchOperands(ByteCodeReader *reader) override;
};

class Index8Instruction : public Instruction {
public:
    unsigned index = 0;

    void fetchOperands(ByteCodeReader *reader) override;

};

class Index16Instruction : public Instruction {
public:
    unsigned index = 0;

    void fetchOperands(ByteCodeReader *reader) override;
};

Instruction *newInstruction(unsigned char opcode);


#endif //HOTPOTJVM_INSTRUCTION_H
