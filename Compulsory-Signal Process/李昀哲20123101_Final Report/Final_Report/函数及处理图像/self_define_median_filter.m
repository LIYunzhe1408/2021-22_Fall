function x = self_define_median_filter(img_resize,n,height,width)
%����һ���������Ի�ȡ����ĻҶ�ֵ
img_salt_pepper_copy =img_resize;  
for i=1:height  
     for j=1:width 
         %ȡ����n��n�еľ���
        matrix=img_salt_pepper_copy(i:i+(n-1),j:j+(n-1)); 
        matrix = reshape(matrix, 1, n*n);
        median_num = median(matrix);
        img_resize(i+(n-1)/2,j+(n-1)/2)=median_num;   %��ģ���Ԫ�ص���ֵ����ģ������λ�õ�Ԫ��  
    end  
end   
 img_resize=uint8(img_resize((n-1)/2+1:height+(n-1)/2,(n-1)/2+1:width+(n-1)/2));
 x = img_resize;


F2=fft2(im2double(img_resize)); %FFT
F2=fftshift(F2); %FFTƵ��ƽ��
F2 = abs(F2);
T2 = log(F2+1);

%subplot(3,2,3),imshow(img_resize), title('median');
%subplot(3,2,4),imshow(T2,[]), title('median_freq');
end