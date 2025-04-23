package com.example.miniotest.comtroller;

import com.example.miniotest.Utils.MinioUtils;
import org.apache.tomcat.util.http.fileupload.IOUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

@RestController
@RequestMapping("/minio")
public class MinioController {

    @Autowired
    private MinioUtils minioUtils;

    @PostMapping("/upload")
    public String uploadFile(@RequestParam("file") MultipartFile file) {
        return minioUtils.uploadFile(file);
    }

    @GetMapping("/download/{fileName}")
    public void downloadFile(@PathVariable String fileName, HttpServletResponse response) {
        System.out.println(fileName);
        InputStream inputStream = minioUtils.downloadFile(fileName);
        if (inputStream != null) {
            response.setContentType("application/octet-stream");
            response.setHeader("Content-Disposition", "attachment; filename=\"" + fileName + "\"");
            try {
               IOUtils.copy(inputStream, response.getOutputStream());
                response.flushBuffer();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @DeleteMapping("/delete/{fileName}")
    public String deleteFile(@PathVariable String fileName) {
        return minioUtils.deleteFile(fileName) ? "File deleted successfully!" : "Error deleting file!";
    }

    @GetMapping("/list")
    public List<String> listFiles() {
        return minioUtils.listFiles();
    }

    @GetMapping("/exists/{fileName}")
    public boolean fileExists(@PathVariable String fileName) {
        return minioUtils.fileExists(fileName);
    }

    @GetMapping("/url/{fileName}")
    public String getFileUrl(@PathVariable String fileName) {
        return minioUtils.getFileUrl(fileName);
    }
}
