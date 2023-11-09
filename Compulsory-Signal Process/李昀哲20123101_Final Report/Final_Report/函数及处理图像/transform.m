function T= transform(img)
F=fft2(im2double(img));
%FFT频谱平移
F=fftshift(F); 
F = abs(F);
%频谱对数变换
T = log(F+1);
end