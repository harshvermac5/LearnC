def zap(y):
    print ('Y start zap:', y)
    y = 'changed'
    print('Y end zap:', y)

x = 'original'
print('X before zap:', x)
zap(x)
print('X after zap:', x)
