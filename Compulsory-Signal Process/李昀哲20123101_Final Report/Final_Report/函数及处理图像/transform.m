function T= transform(img)
F=fft2(im2double(img));
%FFTƵ��ƽ��
F=fftshift(F); 
F = abs(F);
%Ƶ�׶����任
T = log(F+1);
end